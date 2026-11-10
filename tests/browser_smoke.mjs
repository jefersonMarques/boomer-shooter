import assert from "node:assert/strict";
import { writeFile } from "node:fs/promises";

import { chromium } from "playwright";
import { PNG } from "pngjs";

const browser = await chromium.launch({
    headless: true,
    args: [
        "--enable-webgl",
        "--use-gl=angle",
        "--use-angle=swiftshader",
        "--enable-unsafe-swiftshader"
    ]
});

try {
    const page = await browser.newPage({
        viewport: { width: 1280, height: 900 }
    });
    const errors = [];

    page.on("pageerror", (error) => {
        errors.push(error.message);
    });
    page.on("console", (message) => {
        if (message.type() === "error" && !message.text().startsWith("Click to capture")) {
            errors.push(message.text());
        }
    });

    await page.goto("http://127.0.0.1:8000/boomer_shooter.html", {
        waitUntil: "load"
    });

    const canvas = page.locator("canvas");
    await canvas.waitFor({ state: "visible", timeout: 30000 });
    await page.waitForTimeout(2500);

    const screenshot = await canvas.screenshot();
    await writeFile("browser-smoke.png", screenshot);

    const { width, height, data } = PNG.sync.read(screenshot);
    const colors = new Set();

    for (let y = 8; y < height - 8; y += 24) {
        for (let x = 8; x < width - 8; x += 24) {
            const index = (y * width + x) * 4;
            colors.add(`${data[index]},${data[index + 1]},${data[index + 2]}`);
        }
    }

    assert.ok(width > 0 && height > 0, "Game canvas has no dimensions");
    assert.ok(colors.size >= 4, "Game canvas appears blank or uniform");
    assert.deepEqual(errors, [], "Browser reported runtime errors");

    console.log(`Browser render smoke test passed: ${width}x${height}, ${colors.size} colors`);
} finally {
    await browser.close();
}
