#include "level/LevelWorld.hpp"

#include <cstdlib>
#include <iostream>
#include <source_location>
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

    Require(level.Interact(54.9F, 24.0F, message));
    Require(level.IsDoorOpen("D06"));
    Require(level.CanOccupy(55.0F, 26.0F, 0.30F));

    Require(level.Interact(72.3F, 17.6F, message));
    Require(level.IsDoorOpen("D07"));
    Require(level.CanOccupy(75.0F, 14.0F, 0.30F));

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
