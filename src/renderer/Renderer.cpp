#include "renderer/Renderer.hpp"

#include <SDL3/SDL.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>

namespace {
const char* kVertexShader = R"( #version 300 es
precision highp float;
layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec3 aColor;
uniform vec3 uCameraPosition;
uniform vec2 uCameraAngles;
uniform float uAspect;
out vec3 vColor;
void main()
{
    vec3 point = aPosition - uCameraPosition;
    float cy = cos(uCameraAngles.x);
    float sy = sin(uCameraAngles.x);
    vec3 horizontal = vec3(cy * point.x + sy * point.z, point.y,
                           -sy * point.x + cy * point.z);
    float cp = cos(uCameraAngles.y);
    float sp = sin(uCameraAngles.y);
    vec3 view = vec3(horizontal.x,
                     cp * horizontal.y + sp * horizontal.z,
                     -sp * horizontal.y + cp * horizontal.z);
    float nearPlane = 0.1;
    float farPlane = 250.0;
    float focal = 1.7320508;
    gl_Position = vec4(focal * view.x / uAspect,
                       focal * view.y,
                       (farPlane + nearPlane) / (nearPlane - farPlane) * view.z
                         + (2.0 * farPlane * nearPlane) / (nearPlane - farPlane),
                       -view.z);
    vColor = aColor;
}
)";

const char* kFragmentShader = R"( #version 300 es
precision mediump float;
in vec3 vColor;
out vec4 fragmentColor;
void main()
{
    fragmentColor = vec4(vColor, 1.0);
}
)";

GLuint CompileShader(GLenum type, const char* source)
{
    const GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    GLint succeeded = GL_FALSE;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &succeeded);

    if (succeeded == GL_FALSE) {
        std::array<char, 2048> message{};
        glGetShaderInfoLog(shader, static_cast<GLsizei>(message.size()), nullptr, message.data());
        SDL_LogError(SDL_LOG_CATEGORY_RENDER, "Shader compilation failed: %s", message.data());
        glDeleteShader(shader);
        return 0;
    }

    return shader;
}
}

bool Renderer::Initialize(const LevelWorld& level)
{
    const GLuint vertexShader = CompileShader(GL_VERTEX_SHADER, kVertexShader);
    const GLuint fragmentShader = CompileShader(GL_FRAGMENT_SHADER, kFragmentShader);

    if (vertexShader == 0 || fragmentShader == 0) {
        if (vertexShader != 0) {
            glDeleteShader(vertexShader);
        }
        if (fragmentShader != 0) {
            glDeleteShader(fragmentShader);
        }
        return false;
    }

    program_ = glCreateProgram();
    glAttachShader(program_, vertexShader);
    glAttachShader(program_, fragmentShader);
    glLinkProgram(program_);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    GLint linked = GL_FALSE;
    glGetProgramiv(program_, GL_LINK_STATUS, &linked);

    if (linked == GL_FALSE) {
        std::array<char, 2048> message{};
        glGetProgramInfoLog(program_, static_cast<GLsizei>(message.size()), nullptr, message.data());
        SDL_LogError(SDL_LOG_CATEGORY_RENDER, "Shader link failed: %s", message.data());
        Shutdown();
        return false;
    }

    glGenVertexArrays(1, &vertexArray_);
    glBindVertexArray(vertexArray_);
    glGenBuffers(1, &vertexBuffer_);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer_);
     glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                          reinterpret_cast<void*>(3 * sizeof(float)));
    glBindVertexArray(0);
    glEnable(GL_DEPTH_TEST);
    RefreshLevel(level);
    return true;
}

void Renderer::Draw(const PlayerController& player, int width, int height) const
{
    if (width <= 0 || height <= 0) {
        return;
    }

    glViewport(0, 0, width, height);
    glClearColor(0.035F, 0.025F, 0.055F, 1.0F);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(program_);

    const Vec3& camera = player.GetPosition();
    glUniform3f(glGetUniformLocation(program_, "uCameraPosition"),
                camera.x, camera.y, camera.z);
    glUniform2f(glGetUniformLocation(program_, "uCameraAngles"),
                player.GetYaw(), player.GetPitch());
    glUniform1f(glGetUniformLocation(program_, "uAspect"),
                static_cast<float>(width) / static_cast<float>(height));

    glBindVertexArray(vertexArray_);
    glDrawArrays(GL_TRIANGLES, 0, vertexCount_);
    glBindVertexArray(0);
}

void Renderer::Shutdown()
{
    if (vertexBuffer_ != 0) {
        glDeleteBuffers(1, &vertexBuffer_);
        vertexBuffer_ = 0;
    }
    if (vertexArray_ != 0) {
        glDeleteVertexArrays(1, &vertexArray_);
        vertexArray_ = 0;
    }
    if (program_ != 0) {
        glDeleteProgram(program_);
        program_ = 0;
    }
}

void Renderer::RefreshLevel(const LevelWorld& level)
{
    if (renderedRevision_ == level.GetRevision()) {
        return;
    }

    vertices_.clear();
    BuildScene(level);
    vertexCount_ = static_cast<GLsizei>(vertices_.size() / 6);

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer_);
    glBufferData(GL_ARRAY_BUFFER,
                 static_cast<GLsizeiptr>(vertices_.size() * sizeof(float)),
                 vertices_.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    renderedRevision_ = level.GetRevision();
}

namespace {
bool IsInRoom(const LevelRoom& room, float x, float y)
{
    bool inside = false;
    const auto& points = room.outline;
    for (std::size_t i = 0, j = points.size() - 1; i < points.size(); j = i++) {
        const PlanPoint& a = points[i];
        const PlanPoint& b = points[j];
        if ((a.y > y) != (b.y > y)) {
            const float edgeX = a.x + (y - a.y) * (b.x - a.x) / (b.y - a.y);
            if (x < edgeX) {
                inside = !inside;
            }
        }
    }
    return inside;
}

Vec3 RoomColor(const std::string& id)
{
    if (id == "S1" || id == "S2") {
        return {0.31F, 0.36F, 0.37F};
    }
    if (id == "S5") {
        return {0.27F, 0.31F, 0.28F};
    }
    if (id == "S6") {
        return {0.45F, 0.31F, 0.18F};
    }
    return {0.29F, 0.32F, 0.36F};
}

Vec3 PropColor(const LevelProp& prop)
{
    if (prop.type == "nonTraversableGlass") {
        return {0.18F, 0.38F, 0.42F};
    }
    if (prop.type == "conveyor") {
        return {0.18F, 0.22F, 0.20F};
    }
    if (prop.type == "movableCabinet") {
        return {0.49F, 0.28F, 0.15F};
    }
    if (prop.type == "lift") {
        return {0.56F, 0.43F, 0.20F};
    }
    if (prop.type == "raisedWalkway" || prop.type == "raisedInspectionPlatform") {
        return {0.37F, 0.40F, 0.34F};
    }
    return {0.40F, 0.35F, 0.29F};
}

Vec3 MarkerColor(const std::string& type)
{
    if (type == "convertedWorker" || type == "industrialSentinel") {
        return {0.73F, 0.16F, 0.15F};
    }
    if (type == "switch" || type == "identityTerminal") {
        return {0.93F, 0.70F, 0.19F};
    }
    if (type == "weaponPickup") {
        return {0.28F, 0.85F, 0.52F};
    }
    if (type == "ammoPickup") {
        return {0.22F, 0.69F, 0.78F};
    }
    return {0.54F, 0.39F, 0.65F};
}
}

void Renderer::BuildScene(const LevelWorld& level)
{
    const LevelDefinition& data = level.GetDefinition();

    for (const LevelRoom& room : data.rooms) {
        std::vector<float> xCuts;
        std::vector<float> yCuts;

        for (const PlanPoint& point : room.outline) {
            xCuts.push_back(point.x);
            yCuts.push_back(point.y);
        }

        std::sort(xCuts.begin(), xCuts.end());
        std::sort(yCuts.begin(), yCuts.end());
        xCuts.erase(std::unique(xCuts.begin(), xCuts.end()), xCuts.end());
        yCuts.erase(std::unique(yCuts.begin(), yCuts.end()), yCuts.end());

        for (std::size_t xIndex = 1; xIndex < xCuts.size(); ++xIndex) {
            for (std::size_t yIndex = 1; yIndex < yCuts.size(); ++yIndex) {
                const float minX = xCuts[xIndex - 1];
                const float maxX = xCuts[xIndex];
                const float minY = yCuts[yIndex - 1];
                const float maxY = yCuts[yIndex];
                const float centerX = (minX + maxX) * 0.5F;
                const float centerY = (minY + maxY) * 0.5F;
                if (!IsInRoom(room, centerX, centerY)) {
                    continue;
                }

                const Vec3 center{centerX, 0.0F, -centerY};
                const Vec3 dimensions{maxX - minX, 0.18F, maxY - minY};
                const Vec3 floorColor = RoomColor(room.id);

                AddBox({center.x, room.floorZ - 0.09F, center.z},
                       dimensions, floorColor);
                AddBox({center.x, room.ceilingZ + 0.09F, center.z},
                       dimensions, {0.15F, 0.17F, 0.20F});
            }
        }
    }

    for (const LevelWall& wall : level.GetWalls()) {
        const float midX = (wall.start.x + wall.end.x) * 0.5F;
        const float midY = (wall.start.y + wall.end.y) * 0.5F;
        const float width = std::max(0.20F, std::abs(wall.end.x - wall.start.x));
        const float depth = std::max(0.20F, std::abs(wall.end.y - wall.start.y));

        AddBox({midX, (wall.floorZ + wall.ceilingZ) * 0.5F, -midY},
               {width, wall.ceilingZ - wall.floorZ, depth},
               {0.34F, 0.38F, 0.38F});
    }

    for (const LevelDoor& door : data.doors) {
        if (door.isOpen) {
            continue;
        }

        const float width = std::max(0.25F, std::abs(door.end.x - door.start.x));
        const float depth = std::max(0.25F, std::abs(door.end.y - door.start.y));
        const Vec3 color = door.id == "D03"
            ? Vec3{0.65F, 0.13F, 0.16F}
            : door.id == "D06"
                ? Vec3{0.34F, 0.38F, 0.38F}
                : Vec3{0.62F, 0.47F, 0.20F};

        AddBox({(door.start.x + door.end.x) * 0.5F, 1.3F,
                -(door.start.y + door.end.y) * 0.5F},
               {width, 2.6F, depth}, color);
    }

    for (const LevelProp& prop : data.props) {
        if (prop.id == "secretCabinet" && level.IsDoorOpen("D06")) {
            continue;
        }

        if (prop.type == "ramp") {
            AddRamp(prop);
            continue;
        }

        const float middleX = (prop.bounds.minX + prop.bounds.maxX) * 0.5F;
        const float middleY = (prop.bounds.minY + prop.bounds.maxY) * 0.5F;
        AddBox({middleX, (prop.bottomZ + prop.topZ) * 0.5F, -middleY},
               {prop.bounds.maxX - prop.bounds.minX,
                prop.topZ - prop.bottomZ,
                prop.bounds.maxY - prop.bounds.minY},
               PropColor(prop));
    }

    for (const LevelEntity& entity : data.entities) {
        if (entity.type == "playerStart" || entity.type == "audioRecording") {
            continue;
        }

        const float height = entity.type == "industrialSentinel" ? 1.35F : 0.8F;
        AddBox({entity.position.x, entity.floorZ + height * 0.5F,
                -entity.position.y},
               {0.65F, height, 0.65F}, MarkerColor(entity.type));
    }
}

void Renderer::AddTriangle(const Vec3& a, const Vec3& b, const Vec3& c,
                           const Vec3& color)
{
    for (const Vec3& position : {a, b, c}) {
        vertices_.insert(vertices_.end(),
                         {position.x, position.y, position.z,
                          color.x, color.y, color.z});
    }
}

void Renderer::AddRamp(const LevelProp& prop)
{
    const PlanRect& area = prop.bounds;
    const Vec3 northWest{area.minX, prop.rampStartZ, -area.maxY};
    const Vec3 northEast{area.maxX, prop.rampEndZ, -area.maxY};
    const Vec3 southEast{area.maxX, prop.rampEndZ, -area.minY};
    const Vec3 southWest{area.minX, prop.rampStartZ, -area.minY};
    const Vec3 color{0.38F, 0.37F, 0.29F};

    AddTriangle(northWest, northEast, southEast, color);
    AddTriangle(northWest, southEast, southWest, color);
}
void Renderer::AddBox(const Vec3& center, const Vec3& dimensions, const Vec3& color)
{
    const float halfX = dimensions.x * 0.5F;
    const float halfY = dimensions.y * 0.5F;
    const float halfZ = dimensions.z * 0.5F;

    const std::array<Vec3, 8> corners{{
        {center.x - halfX, center.y - halfY, center.z - halfZ},
        {center.x + halfX, center.y - halfY, center.z - halfZ},
        {center.x + halfX, center.y + halfY, center.z - halfZ},
        {center.x - halfX, center.y + halfY, center.z - halfZ},
        {center.x - halfX, center.y - halfY, center.z + halfZ},
        {center.x + halfX, center.y - halfY, center.z + halfZ},
        {center.x + halfX, center.y + halfY, center.z + halfZ},
        {center.x - halfX, center.y + halfY, center.z + halfZ}
    }};

    const std::array<std::array<int, 4>, 6> faces{{
        {{0, 1, 2, 3}}, {{5, 4, 7, 6}}, {{4, 0, 3, 7}},
        {{1, 5, 6, 2}}, {{3, 2, 6, 7}}, {{4, 5, 1, 0}}
    }};
    const std::array<float, 6> shades{{0.75F, 0.75F, 0.62F, 0.62F, 1.0F, 0.45F}};
    const std::array<int, 6> indices{{0, 1, 2, 0, 2, 3}};

    for (std::size_t face = 0; face < faces.size(); ++face) {
        for (const int index : indices) {
            const Vec3& point = corners[faces[face][index]];
            vertices_.insert(vertices_.end(), {
                point.x, point.y, point.z,
                color.x * shades[face], color.y * shades[face], color.z * shades[face]
            });
        }
    }
}
