#include "level/LevelWorld.hpp"

#include "LevelData.generated.hpp"

#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>

namespace {
constexpr float kWallThickness = 0.20F;
constexpr float kTolerance = 0.001F;
constexpr float kInteractionDistance = 2.3F;

bool IsClose(float first, float second)
{
    return std::abs(first - second) < kTolerance;
}

bool PointInsidePolygon(const std::vector<PlanPoint>& vertices, float x, float y)
{
    bool inside = false;

    for (std::size_t i = 0, j = vertices.size() - 1; i < vertices.size(); j = i++) {
        const PlanPoint& a = vertices[i];
        const PlanPoint& b = vertices[j];

        const float cross = (x - a.x) * (b.y - a.y) - (y - a.y) * (b.x - a.x);
        const float dot = (x - a.x) * (x - b.x) + (y - a.y) * (y - b.y);
        if (std::abs(cross) < kTolerance && dot <= kTolerance) {
            return true;
        }

        const bool spansY = (a.y > y) != (b.y > y);
        if (spansY) {
            const float boundaryX = a.x + (y - a.y) * (b.x - a.x) / (b.y - a.y);
            if (x < boundaryX) {
                inside = !inside;
            }
        }
    }

    return inside;
}

bool CircleOverlapsRect(float x, float y, float radius, const PlanRect& rect)
{
    const float closestX = std::clamp(x, rect.minX, rect.maxX);
    const float closestY = std::clamp(y, rect.minY, rect.maxY);
    const float deltaX = x - closestX;
    const float deltaY = y - closestY;

    return deltaX * deltaX + deltaY * deltaY < radius * radius;
}

PlanRect SegmentBounds(const PlanPoint& start, const PlanPoint& end)
{
    const float halfThickness = kWallThickness * 0.5F;
    return {
        std::min(start.x, end.x) - halfThickness,
        std::min(start.y, end.y) - halfThickness,
        std::max(start.x, end.x) + halfThickness,
        std::max(start.y, end.y) + halfThickness
    };
}

float DistanceSquared(float firstX, float firstY, float secondX, float secondY)
{
    const float deltaX = firstX - secondX;
    const float deltaY = firstY - secondY;
    return deltaX * deltaX + deltaY * deltaY;
}

bool IsNear(float x, float y, const PlanPoint& target)
{
    return DistanceSquared(x, y, target.x, target.y) <
        kInteractionDistance * kInteractionDistance;
}
}

void LevelWorld::Load()
{
    definition_ = GeneratedLevel::CreateL01();
    completed_ = false;
    BuildWalls();
    ++revision_;
}

bool LevelWorld::CanOccupy(float mapX, float mapY, float radius) const
{
    bool insideRoom = false;

    for (const LevelRoom& room : definition_.rooms) {
        if (PointInsidePolygon(room.outline, mapX, mapY)) {
            insideRoom = true;
            break;
        }
    }

    if (!insideRoom) {
        return false;
    }

    for (const LevelWall& wall : walls_) {
        if (CircleOverlapsRect(mapX, mapY, radius, SegmentBounds(wall.start, wall.end))) {
            return false;
        }
    }

    for (const LevelDoor& door : definition_.doors) {
        if (!door.isOpen &&
            CircleOverlapsRect(mapX, mapY, radius, SegmentBounds(door.start, door.end))) {
            return false;
        }
    }

    for (const LevelProp& prop : definition_.props) {
        if (!prop.blocksPlayer) {
            continue;
        }
        if (prop.id == "secretCabinet" && IsDoorOpen("D06")) {
            continue;
        }
        if (CircleOverlapsRect(mapX, mapY, radius, prop.bounds)) {
            return false;
        }
    }

    return true;
}

bool LevelWorld::IsDoorOpen(const std::string& id) const
{
    for (const LevelDoor& door : definition_.doors) {
        if (door.id == id) {
            return door.isOpen;
        }
    }
    return false;
}

bool LevelWorld::Interact(float mapX, float mapY, std::string& message)
{
    for (const LevelEntity& entity : definition_.entities) {
        if (!IsNear(mapX, mapY, entity.position)) {
            continue;
        }

        if (entity.id == "identityTerminal") {
            SetDoorOpen("D01");
            message = "TERMINAL: D01 UNLOCKED";
            return true;
        }

        if (entity.id == "sortingLineLever") {
            SetDoorOpen("D07");
            message = "SORTING LINE STOPPED: ELEVATOR UNLOCKED";
            return true;
        }

        if (entity.id == "elevatorControl") {
            if (IsDoorOpen("D07")) {
                completed_ = true;
                message = "L01 COMPLETE: NEXT FLOOR L02";
            } else {
                message = "ELEVATOR LOCKED";
            }
            return true;
        }
    }

    for (const LevelProp& prop : definition_.props) {
        if (prop.id != "secretCabinet") {
            continue;
        }

        const PlanPoint center{
            (prop.bounds.minX + prop.bounds.maxX) * 0.5F,
            (prop.bounds.minY + prop.bounds.maxY) * 0.5F
        };

        if (IsNear(mapX, mapY, center)) {
            SetDoorOpen("D06");
            message = "SECRET DISCOVERED: 1/1";
            return true;
        }
    }

    message = "NO CONTROL IN RANGE";
    return false;
}

bool LevelWorld::IsComplete() const
{
    return completed_;
}

std::size_t LevelWorld::GetRevision() const
{
    return revision_;
}

const LevelDefinition& LevelWorld::GetDefinition() const
{
    return definition_;
}

const std::vector<LevelWall>& LevelWorld::GetWalls() const
{
    return walls_;
}

void LevelWorld::SetDoorOpen(const std::string& id)
{
    for (LevelDoor& door : definition_.doors) {
        if (door.id == id && !door.isOpen) {
            door.isOpen = true;
            ++revision_;
            return;
        }
    }
}

void LevelWorld::BuildWalls()
{
    walls_.clear();

    for (const LevelRoom& room : definition_.rooms) {
        const std::size_t count = room.outline.size();

        for (std::size_t index = 0; index < count; ++index) {
            const PlanPoint& start = room.outline[index];
            const PlanPoint& end = room.outline[(index + 1) % count];
            const bool vertical = IsClose(start.x, end.x);
            const bool horizontal = IsClose(start.y, end.y);

            if (!vertical && !horizontal) {
                continue;
            }

            const float from = vertical ? start.y : start.x;
            const float to = vertical ? end.y : end.x;
            const float lower = std::min(from, to);
            const float upper = std::max(from, to);

            std::vector<std::pair<float, float>> openings;

            for (const LevelDoor& door : definition_.doors) {
                const bool aligned = vertical
                    ? IsClose(door.start.x, start.x) && IsClose(door.end.x, start.x)
                    : IsClose(door.start.y, start.y) && IsClose(door.end.y, start.y);

                if (!aligned) {
                    continue;
                }

                const float doorFrom = vertical ? door.start.y : door.start.x;
                const float doorTo = vertical ? door.end.y : door.end.x;
                const float openingStart = std::max(lower, std::min(doorFrom, doorTo));
                const float openingEnd = std::min(upper, std::max(doorFrom, doorTo));

                if (openingEnd > openingStart + kTolerance) {
                    openings.emplace_back(openingStart, openingEnd);
                }
            }

            std::sort(openings.begin(), openings.end());
            float cursor = lower;

            const auto addWall = [&](float sectionStart, float sectionEnd) {
                if (sectionEnd <= sectionStart + kTolerance) {
                    return;
                }

                const PlanPoint a = vertical
                    ? PlanPoint{start.x, sectionStart}
                    : PlanPoint{sectionStart, start.y};
                const PlanPoint b = vertical
                    ? PlanPoint{start.x, sectionEnd}
                    : PlanPoint{sectionEnd, start.y};

                walls_.push_back({a, b, room.floorZ, room.ceilingZ});
            };

            for (const auto& [openingStart, openingEnd] : openings) {
                addWall(cursor, openingStart);
                cursor = std::max(cursor, openingEnd);
            }

            addWall(cursor, upper);
        }
    }
}
