#pragma once

#include <SDL3/SDL.h>

struct Vec3 {
    float x = 0.0F;
    float y = 0.0F;
    float z = 0.0F;
};

class PlayerController final {
public:
    void Update(float deltaSeconds);
    void Look(float deltaX, float deltaY);

    [[nodiscard]] const Vec3& GetPosition() const;
    [[nodiscard]] float GetYaw() const;
    [[nodiscard]] float GetPitch() const;

private:
    Vec3 position_{0.0F, 1.6F, 5.0F};
    float yaw_ = 0.0F;
    float pitch_ = 0.0F;
};
