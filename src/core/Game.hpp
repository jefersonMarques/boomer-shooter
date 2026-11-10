#pragma once

#include <SDL3/SDL.h>

#include "gameplay/PlayerController.hpp"
#include "renderer/Renderer.hpp"

class Game final {
public:
    Game() = default;
    ~Game();

    [[nodiscard]] bool Initialize();
    void Run();

private:
    void Frame();
    void ProcessEvents();
    void Shutdown();

    SDL_Window* window_ = nullptr;
    SDL_GLContext context_ = nullptr;
    Renderer renderer_;
    PlayerController player_;
    bool running_ = true;
    bool mouseCaptured_ = false;
    double accumulator_ = 0.0;
    Uint64 previousCounter_ = 0;
};
