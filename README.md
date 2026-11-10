# Boomer Shooter

A browser-first retro FPS prototype inspired by the **pace and atmosphere** of classic 1990s shooters. All game logic and rendering are written in **C++20**, with a native Linux build and a WebAssembly/WebGL2 build.

> Prototype 0.1 is a **technical bootstrap**, not yet a complete game. It renders a colored 3D test corridor with WASD movement and mouse look. There are no textures, weapons, enemies, player avatars, touch controls, or multiplayer yet.

## Technology

- C++20
- SDL3 (fetched by CMake at pinned release `3.4.2`)
- OpenGL ES 3.0 / WebGL2
- Emscripten for WebAssembly
- CMake / Ninja

## Build on Ubuntu / WSL

Install prerequisites:

```bash
sudo apt update
sudo apt install -y build-essential cmake ninja-build git python3 \
    libgles2-mesa-dev libegl1-mesa-dev libx11-dev libxcursor-dev \
    libxi-dev libxrandr-dev libxext-dev libxfixes-dev libxkbcommon-dev \
    libxss-dev libxtst-dev libxinerama-dev libxkbcommon-x11-dev libx11-xcb-dev
```

Configure and build:

```bash
cmake -S . -B build/native -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build/native
./build/native/boomer_shooter
```

A working graphical session (such as WSLg) with OpenGL ES 3 support is required for the native target.

## Build for the browser

Install the Emscripten SDK separately. Then load its environment:

```bash
source ~/tools/emsdk/emsdk_env.sh
emcmake cmake -S . -B build/web -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build/web
python3 -m http.server 8000 --directory build/web
```

Open <http://localhost:8000/boomer_shooter.html>. Do not open the HTML using a `file://` URL.

If CMake has been run before using the native toolchain, always use a separate browser build directory to prevent cache conflicts.

## Controls (desktop browser / native)

| Input | Action |
| --- | --- |
| WASD / arrow keys | Move |
| Mouse movement | Look around |
| Left click | Capture mouse |
| Left Shift | Run |
| Escape | Release mouse |

The first prototype does not include touchscreen controls. Smartphone support is planned after the rendering and movement loop have been verified.

## Roadmap

1. WebAssembly and native bootstrap with a minimal 3D test scene.
2. Proper player collision, movement physics and a retro renderer.
3. Weapon feedback and enemy state machines.
4. Optional uploaded-face avatar with a reactive HUD (process locally by default).
5. Responsive touch controls, performance profiling and browser testing.
6. User accounts, progress persistence and multiplayer as a later phase.

## Project principles

- The game runtime does not require a JavaScript game engine.
- No privileged credentials are embedded in the browser client.
- Use original or properly licensed artwork, audio, and levels.
- Keep platform-specific code isolated from game logic.
- Avoid a fully general-purpose engine until the playable prototype proves it necessary.

## Game design and story

The game's initial creative direction is documented under [docs/game-design](docs/game-design/README.md), including the **O Último Rosto** story, worldbuilding, visual direction, gameplay pillars, optional face personalization, and the initial vertical-slice scope. These are design references, not completed prototype features.
