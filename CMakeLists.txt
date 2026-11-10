cmake_minimum_required(VERSION 3.24)

project(boomer_shooter VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

set(SDL_SHARED OFF CACHE BOOL "Build SDL as a shared library" FORCE)
set(SDL_STATIC ON CACHE BOOL "Build SDL as a static library" FORCE)
set(SDL_TEST_LIBRARY OFF CACHE BOOL "Build SDL test library" FORCE)

FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-3.4.2
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(SDL3)

add_executable(boomer_shooter
    src/main.cpp
    src/core/Game.cpp
    src/gameplay/PlayerController.cpp
    src/renderer/Renderer.cpp
)

target_include_directories(boomer_shooter PRIVATE src)
target_link_libraries(boomer_shooter PRIVATE SDL3::SDL3)

if(MSVC)
    target_compile_options(boomer_shooter PRIVATE /W4)
else()
    target_compile_options(boomer_shooter PRIVATE -Wall -Wextra -Wpedantic)
endif()

if(EMSCRIPTEN)
    set_target_properties(boomer_shooter PROPERTIES SUFFIX ".html")
    target_link_options(boomer_shooter PRIVATE
        "-sMIN_WEBGL_VERSION=2"
        "-sMAX_WEBGL_VERSION=2"
        "-sALLOW_MEMORY_GROWTH=1"
        "-sASSERTIONS=1"
    )
else()
    find_library(GLESV2_LIBRARY NAMES GLESv2 REQUIRED)
    target_link_libraries(boomer_shooter PRIVATE "${GLESV2_LIBRARY}")
endif()
