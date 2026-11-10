#pragma once

#include <GLES3/gl3.h>

#include <cstddef>
#include <limits>
#include <vector>

#include "gameplay/PlayerController.hpp"
#include "level/LevelWorld.hpp"

class Renderer final {
public:
    [[nodiscard]] bool Initialize(const LevelWorld& level);
    void RefreshLevel(const LevelWorld& level);
    void Draw(const PlayerController& player, int width, int height) const;
    void Shutdown();

private:
    void BuildScene(const LevelWorld& level);
    void AddBox(const Vec3& center, const Vec3& dimensions, const Vec3& color);
    void AddTriangle(const Vec3& a, const Vec3& b, const Vec3& c, const Vec3& color);
    void AddRamp(const LevelProp& prop);

    GLuint program_ = 0;
    GLuint vertexArray_ = 0;
    GLuint vertexBuffer_ = 0;
    GLsizei vertexCount_ = 0;
    std::size_t renderedRevision_ = std::numeric_limits<std::size_t>::max();
    std::vector<float> vertices_;
};
