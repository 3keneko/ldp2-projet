#!/usr/bin/env python3

import random

TYPE_LANE = "SRLT"


for i in range(2, 10):
    file = f"level{i}.csv"
    with open(file, "w") as f:
        f.write("S 1\n")
        for the_id in range(2,13):
            lt = random.choice(TYPE_LANE)
            if lt == "S":
                f.write(f"S {the_id}\n")
            else:
                by_pack = random.randint(1, 4)
                space_in_pack = random.randint(10, 40) if lt != "T" else random.randint(10, 15)
                space_between_packs = random.randint(50, 100)
                first_placement = random.randint(-100, 100)
                size_each = random.randint(30, 50) if lt in "TR" else random.randint(130, 200)
                speeds = [*range(-3, 4)]
                speeds.remove(0)
                speed = random.choice(speeds)
                f.write(f"{lt} {the_id} {by_pack} {space_in_pack} {space_between_packs} {first_placement} {size_each} {speed}\n")

        f.write("F 13\n")
