import json
import sys
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))

from generate_level import generate_level, number, room_outline


class LevelGeneratorTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        path = ROOT / "docs/game-design/levels/l01-layout.json"
        cls.layout = json.loads(path.read_text(encoding="utf-8"))

    def test_canonical_level(self):
        layout = self.layout
        self.assertEqual(layout["levelId"], "L01")
        self.assertEqual(len(layout["rooms"]), 7)
        self.assertEqual(len(layout["openings"]), 7)
        self.assertEqual(layout["progression"]["secretCount"], 1)
        self.assertEqual(
            sum(room.get("secret", False) for room in layout["rooms"]),
            1,
        )

    def test_generated_header_contains_expected_objects(self):
        header = generate_level(self.layout)
        for marker in ("CreateL01", "D01", "D03", "D06", "D07", "S5",
                       "sortingLineLever", "secretCabinet"):
            self.assertIn(marker, header)

    def test_polygon_and_numeric_encoding(self):
        self.assertEqual(number(0), "0.0F")
        self.assertEqual(number(1.2), "1.2F")
        self.assertEqual(
            len(room_outline(self.layout["rooms"][2]["shape"])),
            6,
        )

    def test_unknown_schema_fails(self):
        layout = dict(self.layout)
        layout["schemaVersion"] = 999
        with self.assertRaises(ValueError):
            generate_level(layout)


if __name__ == "__main__":
    unittest.main()
