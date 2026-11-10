#pragma once

#include <SDL3/SDL.h>

#include "level/LevelWorld.hpp"

struct Vec3 {
    float x = 0.0F;
    float y = 0.0F;
    float z = 0.0F;
};

class PlayerController final {
public:
    void Spawn(const PlanPoint& point, float floorZ, float yawDegrees);
    void Update(float deltaSeconds, const LevelWorld& level);
    void Look(float deltaX, float deltaY);

    [[nodiscard]] const Vec3& GetPosition() const;
    [[nodiscard]] float GetYaw() const;
    [[nodiscard]] float GetPitch() const;

private:
    Vec3 position_;
    float yaw_ = 0.0F;
    float pitch_ = 0.0F;
};
