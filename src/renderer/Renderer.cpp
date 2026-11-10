#include "renderer/Renderer.hpp"

#include <SDL3/SDL.h>

#include <array>
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
    float farPlane = 100.0;
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

bool Renderer::Initialize()
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

    BuildScene();
    vertexCount_ = static_cast<GLsizei>(vertices_.size() / 6);

    glGenVertexArrays(1, &vertexArray_);
    glBindVertexArray(vertexArray_);
    glGenBuffers(1, &vertexBuffer_);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer_);
    glBufferData(GL_ARRAY_BUFFER,
                 static_cast<GLsizeiptr>(vertices_.size() * sizeof(float)),
                 vertices_.data(), GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                          reinterpret_cast<void*>(3 * sizeof(float)));
    glBindVertexArray(0);
    glEnable(GL_DEPTH_TEST);
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

void Renderer::BuildScene()
{
    AddBox({0.0F, -0.25F, -3.0F}, {8.0F, 0.5F, 22.0F}, {0.26F, 0.23F, 0.22F});
    AddBox({0.0F, 3.55F, -3.0F}, {8.0F, 0.5F, 22.0F}, {0.16F, 0.13F, 0.19F});
    AddBox({-4.0F, 1.65F, -3.0F}, {0.5F, 3.3F, 22.0F}, {0.30F, 0.18F, 0.19F});
    AddBox({4.0F, 1.65F, -3.0F}, {0.5F, 3.3F, 22.0F}, {0.30F, 0.18F, 0.19F});
    AddBox({0.0F, 1.65F, -14.0F}, {8.0F, 3.3F, 0.5F}, {0.40F, 0.18F, 0.16F});
    AddBox({0.0F, 1.65F, 8.0F}, {8.0F, 3.3F, 0.5F}, {0.40F, 0.18F, 0.16F});
    AddBox({-2.8F, 1.2F, -5.0F}, {0.8F, 2.4F, 0.8F}, {0.43F, 0.33F, 0.27F});
    AddBox({2.8F, 1.2F, -5.0F}, {0.8F, 2.4F, 0.8F}, {0.43F, 0.33F, 0.27F});
    AddBox({0.0F, 0.5F, -10.0F}, {1.5F, 1.0F, 1.5F}, {0.55F, 0.26F, 0.18F});
    AddBox({-2.5F, 0.35F, -9.0F}, {1.0F, 0.7F, 1.0F}, {0.33F, 0.30F, 0.25F});
    AddBox({2.5F, 0.35F, -9.0F}, {1.0F, 0.7F, 1.0F}, {0.33F, 0.30F, 0.25F});
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
