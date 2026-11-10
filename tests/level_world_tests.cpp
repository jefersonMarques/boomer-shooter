#include "level/LevelWorld.hpp"

#include <array>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <source_location>
#include <utility>
#include <vector>
#include <string>

namespace {
void Require(bool condition,
             const std::source_location& location = std::source_location::current())
{
    if (!condition) {
        std::cerr << "Level test failed at " << location.file_name()
                  << ":" << location.line() << "\\n";
        std::exit(EXIT_FAILURE);
    }
}

bool HasPath(const LevelWorld& level, const PlanPoint& start,
             const PlanPoint& destination)
{
    constexpr float kStep = 0.25F;
    constexpr int kColumns = 345;
    constexpr int kRows = 149;
    constexpr float kTargetDistance = 0.55F;

    const auto index = [](int x, int y) {
        return static_cast<std::size_t>(y * kColumns + x);
    };

    std::vector<bool> visited(kColumns * kRows, false);
    std::vector<std::pair<int, int>> frontier;
    const int startX = static_cast<int>(std::lround(start.x / kStep));
    const int startY = static_cast<int>(std::lround(start.y / kStep));

    frontier.emplace_back(startX, startY);
    visited[index(startX, startY)] = true;

    constexpr std::array<std::pair<int, int>, 4> directions{{
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    }};

    for (std::size_t position = 0; position < frontier.size(); ++position) {
        const auto [gridX, gridY] = frontier[position];
        const float x = static_cast<float>(gridX) * kStep;
        const float y = static_cast<float>(gridY) * kStep;

        const float offsetX = x - destination.x;
        const float offsetY = y - destination.y;
        if (offsetX * offsetX + offsetY * offsetY <
            kTargetDistance * kTargetDistance) {
            return true;
        }

        for (const auto [deltaX, deltaY] : directions) {
            const int nextX = gridX + deltaX;
            const int nextY = gridY + deltaY;

            if (nextX < 0 || nextY < 0 || nextX >= kColumns || nextY >= kRows ||
                visited[index(nextX, nextY)]) {
                continue;
            }

            if (!level.CanOccupy(nextX * kStep, nextY * kStep, 0.30F)) {
                continue;
            }

            visited[index(nextX, nextY)] = true;
            frontier.emplace_back(nextX, nextY);
        }
    }

    return false;
}
}

int main()
{
    LevelWorld level;
    level.Load();

    Require(level.GetDefinition().rooms.size() == 7);
    Require(level.GetDefinition().doors.size() == 7);
    Require(level.CanOccupy(7.4F, 29.5F, 0.30F));
    Require(!level.CanOccupy(2.0F, 29.5F, 0.30F));

    Require(level.IsDoorOpen("D02"));
    Require(level.IsDoorOpen("D04"));
    Require(level.IsDoorOpen("D05"));
    Require(!level.IsDoorOpen("D01"));
    Require(!level.IsDoorOpen("D03"));
    Require(!level.IsDoorOpen("D06"));
    Require(!level.IsDoorOpen("D07"));

    Require(level.CanOccupy(26.0F, 30.5F, 0.30F));
    Require(level.CanOccupy(38.5F, 19.0F, 0.30F));
    Require(level.CanOccupy(47.0F, 15.5F, 0.30F));

    Require(!level.CanOccupy(13.0F, 30.3F, 0.30F));
    Require(!level.CanOccupy(41.0F, 30.5F, 0.30F));
    Require(!level.CanOccupy(55.0F, 26.0F, 0.30F));
    Require(!level.CanOccupy(75.0F, 14.0F, 0.30F));

    Require(!level.CanOccupy(55.0F, 9.7F, 0.30F));
    Require(level.CanOccupy(60.0F, 14.5F, 0.30F));

    std::string message;
    Require(level.Interact(10.3F, 32.4F, message));
    Require(level.IsDoorOpen("D01"));
    Require(level.CanOccupy(13.0F, 30.3F, 0.30F));
    Require(HasPath(level, {7.4F, 29.5F}, {72.3F, 17.6F}));

    Require(level.Interact(54.9F, 24.0F, message));
    Require(level.IsDoorOpen("D06"));
    Require(level.CanOccupy(55.0F, 26.0F, 0.30F));
    Require(HasPath(level, {54.9F, 23.0F}, {55.0F, 30.0F}));

    Require(level.Interact(72.3F, 17.6F, message));
    Require(level.IsDoorOpen("D07"));
    Require(level.CanOccupy(75.0F, 14.0F, 0.30F));
    Require(HasPath(level, {7.4F, 29.5F}, {79.0F, 14.8F}));

    Require(level.Interact(79.0F, 14.8F, message));
    Require(level.IsComplete());

    const std::size_t previousRevision = level.GetRevision();
    level.Load();

    Require(level.GetRevision() > previousRevision);
    Require(!level.IsDoorOpen("D01"));
    Require(!level.IsDoorOpen("D06"));
    Require(!level.IsDoorOpen("D07"));
    Require(!level.IsComplete());

    return 0;
}
