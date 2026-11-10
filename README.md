# Boomer Shooter

A browser-first retro FPS prototype inspired by the **pace and atmosphere** of classic 1990s shooters. All game logic and rendering are written in **C++20**, with a native Linux build and a WebAssembly/WebGL2 build.

> Prototype 0.1 is a **technical blockout**, not yet a complete game. It renders the L01 industrial complex with rooms, doors, collision and interaction markers. There are no textures, weapons, enemies, player avatars, touch controls, or multiplayer yet.

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
| E | Interact with terminal, cabinet, lever or elevator |
| R | Restart L01 |
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

## L01 blockout

The game now loads its first level, **L01 - Discard Chamber**, from
`docs/game-design/levels/l01-layout.json`. The file is converted at build time
into typed C++ structures by `tools/generate_level.py`, keeping the game
runtime independent of a JSON parser.

The level includes seven sectors, seven doorways, blocking walls, solid cover,
conveyors, placeholders for encounters and the single optional secret room.

### Interactions

- `E` near the identity terminal in S1: open D01.
- `E` near the cabinet in S5: reveal the optional S6 room (D06).
- `E` near the sorting line lever in S5: open D07.
- `E` near the elevator control in S7: finish L01.
- `R`: reset doors and return to the starting position.

Interaction messages currently appear in the game window title.
Enemies and items are colored placeholder blocks, not implemented gameplay.
The raised platforms and ramp are render-only blockout geometry: player
movement still uses a flat floor until elevation-aware collisions are built.

The original plan uses (X east, Y north, Z up). The renderer uses
(X east, Y up, Z south), so map Y is converted to negative world Z.

### Run checks locally

```bash
python3 -m unittest discover -s tests -p 'test_*.py'
cmake -S . -B build/native -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build/native
ctest --test-dir build/native --output-on-failure
```

The GitHub Actions workflow also builds WASM and checks rendering in Chromium.
