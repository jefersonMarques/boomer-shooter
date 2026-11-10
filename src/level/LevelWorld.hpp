#pragma once

#include <cstddef>
#include <string>
#include <vector>

struct PlanPoint {
    float x = 0.0F;
    float y = 0.0F;
};

struct PlanRect {
    float minX = 0.0F;
    float minY = 0.0F;
    float maxX = 0.0F;
    float maxY = 0.0F;
};

struct LevelRoom {
    std::string id;
    std::vector<PlanPoint> outline;
    float floorZ = 0.0F;
    float ceilingZ = 3.0F;
};

struct LevelDoor {
    std::string id;
    PlanPoint start;
    PlanPoint end;
    bool isOpen = false;
};

struct LevelProp {
    std::string id;
    std::string type;
    PlanRect bounds;
    float bottomZ = 0.0F;
    float topZ = 0.8F;
    bool blocksPlayer = false;
    float rampStartZ = 0.0F;
    float rampEndZ = 0.0F;
};

struct LevelEntity {
    std::string id;
    std::string type;
    PlanPoint position;
    float floorZ = 0.0F;
};

struct LevelWall {
    PlanPoint start;
    PlanPoint end;
    float floorZ = 0.0F;
    float ceilingZ = 3.0F;
};

struct LevelDefinition {
    std::vector<LevelRoom> rooms;
    std::vector<LevelDoor> doors;
    std::vector<LevelProp> props;
    std::vector<LevelEntity> entities;
    PlanPoint playerStart;
    float playerFloorZ = 0.0F;
    float playerYawDegrees = 90.0F;
};

class LevelWorld final {
public:
    void Load();

    [[nodiscard]] bool CanOccupy(float mapX, float mapY, float radius) const;
    [[nodiscard]] bool IsDoorOpen(const std::string& id) const;
    [[nodiscard]] bool Interact(float mapX, float mapY, std::string& message);
    [[nodiscard]] bool IsComplete() const;
    [[nodiscard]] std::size_t GetRevision() const;

    [[nodiscard]] const LevelDefinition& GetDefinition() const;
    [[nodiscard]] const std::vector<LevelWall>& GetWalls() const;

private:
    void BuildWalls();
    void SetDoorOpen(const std::string& id);

    LevelDefinition definition_;
    std::vector<LevelWall> walls_;
    std::size_t revision_ = 0;
    bool completed_ = false;
};
