#!/usr/bin/env python3
import argparse
import json
import math
from pathlib import Path


BLOCKING_PROP_TYPES = {
    "solidCrate",
    "solidCart",
    "conveyor",
    "movableCabinet",
    "raisedInspectionPlatform",
}

PROP_HEIGHTS = {
    "solidCrate": 1.1,
    "solidCart": 1.0,
    "conveyor": 0.8,
    "movableCabinet": 2.0,
    "lift": 0.2,
    "ramp": 0.2,
    "nonTraversableGlass": 2.2,
}


def number(value):
    number_value = float(value)
    if not math.isfinite(number_value):
        raise ValueError("Coordinates must be finite")

    formatted = format(number_value, ".7g")
    if "." not in formatted and "e" not in formatted:
        formatted += ".0"
    return f"{formatted}F"


def string(value):
    return json.dumps(value, ensure_ascii=True)


def point(values):
    return "{" + ", ".join(number(value) for value in values[:2]) + "}"


def rect(values):
    return "{" + ", ".join(number(value) for value in values) + "}"


def room_outline(shape):
    if shape["type"] == "rectangle":
        return [
            [shape["minX"], shape["minY"]],
            [shape["maxX"], shape["minY"]],
            [shape["maxX"], shape["maxY"]],
            [shape["minX"], shape["maxY"]],
        ]

    if shape["type"] == "polygon":
        return shape["vertices"]

    raise ValueError(f"Unsupported room shape: {shape['type']}")


def room_record(room):
    outline = room_outline(room["shape"])
    if len(outline) < 3:
        raise ValueError(f"Invalid room: {room['id']}")

    coords = ", ".join(point(item) for item in outline)
    return (
        f"LevelRoom{{{string(room['id'])}, {{{coords}}}, "
        f"{number(room['floorZ'])}, {number(room['ceilingZ'])}}}"
    )


def door_record(door):
    is_open = door["state"] == "open"
    return (
        f"LevelDoor{{{string(door['id'])}, {point(door['segment'][0])}, "
        f"{point(door['segment'][1])}, {str(is_open).lower()}}}"
    )


def prop_record(prop):
    if "bounds" not in prop:
        if "segment" not in prop:
            return None

        start, end = prop["segment"]
        prop = dict(prop)
        prop["bounds"] = [
            min(start[0], end[0]) - 0.1,
            min(start[1], end[1]) - 0.1,
            max(start[0], end[0]) + 0.1,
            max(start[1], end[1]) + 0.1,
        ]

    prop_type = prop["type"]
    bottom_z = 0.8 if prop_type == "nonTraversableGlass" else 0.0
    top_z = prop.get("topZ", PROP_HEIGHTS.get(prop_type, 0.7))

    if prop_type == "raisedWalkway":
        bottom_z = top_z - 0.2

    start_z = prop.get("startZ", 0)
    end_z = prop.get("endZ", 0)
    blocks_player = prop_type in BLOCKING_PROP_TYPES

    return (
        f"LevelProp{{{string(prop['id'])}, {string(prop_type)}, "
        f"{rect(prop['bounds'])}, {number(bottom_z)}, {number(top_z)}, "
        f"{str(blocks_player).lower()}, {number(start_z)}, {number(end_z)}}}"
    )


def entity_record(entity):
    position = entity["position"]
    return (
        f"LevelEntity{{{string(entity['id'])}, {string(entity['type'])}, "
        f"{point(position)}, {number(position[2])}}}"
    )


def generate_level(layout):
    if layout["schemaVersion"] != 1:
        raise ValueError("Unsupported level schema")

    if layout["levelId"] != "L01":
        raise ValueError("Expected L01 level")

    entities = layout["entities"]
    starts = [entity for entity in entities if entity["type"] == "playerStart"]
    if len(starts) != 1:
        raise ValueError("A level must have exactly one playerStart")

    start = starts[0]
    rooms = [room_record(room) for room in layout["rooms"]]
    doors = [door_record(door) for door in layout["openings"]]
    props = [
        generated
        for prop in layout["staticGeometry"]
        if (generated := prop_record(prop)) is not None
    ]
    markers = [entity_record(entity) for entity in entities]

    def field(records):
        return ",\n            ".join(records)

    return f"""#pragma once

#include "level/LevelWorld.hpp"

namespace GeneratedLevel {{

inline LevelDefinition CreateL01()
{{
    return LevelDefinition{{
        {{
            {field(rooms)}
        }},
        {{
            {field(doors)}
        }},
        {{
            {field(props)}
        }},
        {{
            {field(markers)}
        }},
        {point(start['position'])},
        {number(start['position'][2])},
        {number(start.get('yawDegrees', 0))}
    }};
}}

}}
"""


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--input", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()

    with args.input.open(encoding="utf-8") as source:
        layout = json.load(source)

    output = generate_level(layout)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(output, encoding="utf-8")


if __name__ == "__main__":
    main()
