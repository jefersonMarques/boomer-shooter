#pragma once

#include <GLES3/gl3.h>

#include <vector>

#include "gameplay/PlayerController.hpp"

class Renderer final {
public:
    [[nodiscard]] bool Initialize();
    void Draw(const PlayerController& player, int width, int height) const;
    void Shutdown();

private:
    void BuildScene();
    void AddBox(const Vec3& center, const Vec3& dimensions,
                const Vec3& color);

    GLuint program_ = 0;
    GLuint vertexArray_ = 0;
    GLuint vertexBuffer_ = 0;
    GLsizei vertexCount_ = 0;
    std::vector<float> vertices_;
};
