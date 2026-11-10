#include "gameplay/PlayerController.hpp"

#include <algorithm>
#include <cmath>

namespace {
constexpr float kEyeHeight = 1.6F;
constexpr float kWalkSpeed = 5.0F;
constexpr float kRunMultiplier = 1.6F;
constexpr float kLookSensitivity = 0.0025F;
constexpr float kMaxPitch = 1.45F;
constexpr float kPlayerRadius = 0.30F;
constexpr float kRadiansPerDegree = 0.017453292519943295F;
}

void PlayerController::Spawn(const PlanPoint& point, float floorZ,
                             float yawDegrees)
{
    position_ = {point.x, floorZ + kEyeHeight, -point.y};
    yaw_ = yawDegrees * kRadiansPerDegree;
    pitch_ = 0.0F;
}

void PlayerController::Update(float deltaSeconds, const LevelWorld& level)
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
        (keys[SDL_SCANCODE_LSHIFT] || keys[SDL_SCANCODE_RSHIFT]
             ? kRunMultiplier : 1.0F);
    const float sine = std::sin(yaw_);
    const float cosine = std::cos(yaw_);

    const float changeX = (sine * forwardInput + cosine * sideInput) *
        moveSpeed * deltaSeconds;
    const float changeZ = (-cosine * forwardInput + sine * sideInput) *
        moveSpeed * deltaSeconds;

    const float nextX = position_.x + changeX;
    const float nextZ = position_.z + changeZ;

    if (level.CanOccupy(nextX, -position_.z, kPlayerRadius)) {
        position_.x = nextX;
    }
    if (level.CanOccupy(position_.x, -nextZ, kPlayerRadius)) {
        position_.z = nextZ;
    }
}

void PlayerController::Look(float deltaX, float deltaY)
{
    yaw_ += deltaX * kLookSensitivity;
    pitch_ = std::clamp(pitch_ - deltaY * kLookSensitivity,
                        -kMaxPitch, kMaxPitch);
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
