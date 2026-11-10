#include "gameplay/PlayerController.hpp"

#include <algorithm>
#include <cmath>

namespace {
constexpr float kWalkSpeed = 5.0F;
constexpr float kRunMultiplier = 1.6F;
constexpr float kLookSensitivity = 0.0025F;
constexpr float kMaxPitch = 1.45F;
}

void PlayerController::Update(float deltaSeconds)
{
    const bool* keys = SDL_GetKeyboardState(nullptr);
    float forwardInput = 0.0F;
    float sideInput = 0.0F;

    if (keys[SDL_SCANCODE_W] || keys[SDL_SCANCODE_UP]) {
        forwardInput += 1.0F;
    }
    if (keys[SDL_SCANCODE_S] || keys[SDL_SCANCODE_DOWN]) {
        forwardInput -= 1.0F;
    }
    if (keys[SDL_SCANCODE_D] || keys[SDL_SCANCODE_RIGHT]) {
        sideInput += 1.0F;
    }
    if (keys[SDL_SCANCODE_A] || keys[SDL_SCANCODE_LEFT]) {
        sideInput -= 1.0F;
    }

    const float inputLength = std::sqrt(forwardInput * forwardInput + sideInput * sideInput);
    if (inputLength > 0.0F) {
        forwardInput /= inputLength;
        sideInput /= inputLength;
    }

    const float moveSpeed = kWalkSpeed *
        (keys[SDL_SCANCODE_LSHIFT] ? kRunMultiplier : 1.0F);
    const float sine = std::sin(yaw_);
    const float cosine = std::cos(yaw_);

    position_.x += (sine * forwardInput + cosine * sideInput) * moveSpeed * deltaSeconds;
    position_.z += (-cosine * forwardInput + sine * sideInput) * moveSpeed * deltaSeconds;

    position_.x = std::clamp(position_.x, -3.5F, 3.5F);
    position_.z = std::clamp(position_.z, -13.5F, 7.5F);
}

void PlayerController::Look(float deltaX, float deltaY)
{
    yaw_ += deltaX * kLookSensitivity;
    pitch_ = std::clamp(pitch_ - deltaY * kLookSensitivity, -kMaxPitch, kMaxPitch);
}

const Vec3& PlayerController::GetPosition() const
{
    return position_;
}

float PlayerController::GetYaw() const
{
    return yaw_;
}

float PlayerController::GetPitch() const
{
    return pitch_;
}
