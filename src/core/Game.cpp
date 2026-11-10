#include "core/Game.hpp"

#include <algorithm>

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

namespace {
constexpr double kFixedDelta = 1.0 / 60.0;
constexpr double kMaxFrameDelta = 0.05;
}

Game::~Game()
{
    Shutdown();
}

bool Game::Initialize()
{
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL initialization failed: %s", SDL_GetError());
        return false;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    window_ = SDL_CreateWindow("Boomer Shooter - Prototype 0.1", 1280, 720,
                               SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    if (window_ == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Window creation failed: %s", SDL_GetError());
        return false;
    }

    context_ = SDL_GL_CreateContext(window_);
    if (context_ == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "GL context failed: %s", SDL_GetError());
        return false;
    }

    SDL_GL_SetSwapInterval(1);

    if (!renderer_.Initialize()) {
        return false;
    }

    previousCounter_ = SDL_GetPerformanceCounter();
    SDL_Log("Click to capture the mouse. WASD to move, Shift to run, Esc to release mouse.");
    return true;
}

void Game::Run()
{
#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop_arg(
        [](void* context) {
            static_cast<Game*>(context)->Frame();
        },
        this, 0, true);
#else
    while (running_) {
        Frame();
    }
#endif
}

void Game::Frame()
{
    const Uint64 now = SDL_GetPerformanceCounter();
    const double frequency = static_cast<double>(SDL_GetPerformanceFrequency());
    const double elapsed = static_cast<double>(now - previousCounter_) / frequency;
    previousCounter_ = now;

    ProcessEvents();
    if (!running_) {
#ifdef __EMSCRIPTEN__
        emscripten_cancel_main_loop();
#endif
        return;
    }

    accumulator_ += std::min(elapsed, kMaxFrameDelta);
    while (accumulator_ >= kFixedDelta) {
        player_.Update(static_cast<float>(kFixedDelta));
        accumulator_ -= kFixedDelta;
    }

    int width = 0;
    int height = 0;
    SDL_GetWindowSizeInPixels(window_, &width, &height);
    renderer_.Draw(player_, width, height);
    SDL_GL_SwapWindow(window_);
}

void Game::ProcessEvents()
{
    SDL_Event event{};
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_EVENT_QUIT:
            running_ = false;
            break;
        case SDL_EVENT_KEY_DOWN:
            if (event.key.scancode == SDL_SCANCODE_ESCAPE) {
                SDL_SetWindowRelativeMouseMode(window_, false);
                mouseCaptured_ = false;
            }
            break;
        case SDL_EVENT_MOUSE_BUTTON_DOWN:
            if (!mouseCaptured_) {
                mouseCaptured_ = SDL_SetWindowRelativeMouseMode(window_, true);
            }
            break;
        case SDL_EVENT_MOUSE_MOTION:
            if (mouseCaptured_) {
                player_.Look(event.motion.xrel, event.motion.yrel);
            }
            break;
        case SDL_EVENT_WINDOW_FOCUS_LOST:
            SDL_SetWindowRelativeMouseMode(window_, false);
            mouseCaptured_ = false;
            break;
        default:
            break;
        }
    }
}

void Game::Shutdown()
{
    if (context_ != nullptr) {
        renderer_.Shutdown();
        SDL_GL_DestroyContext(context_);
        context_ = nullptr;
    }

    if (window_ != nullptr) {
        SDL_DestroyWindow(window_);
        window_ = nullptr;
    }
    SDL_Quit();
}
