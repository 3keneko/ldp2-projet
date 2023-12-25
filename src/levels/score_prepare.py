#!/usr/bin/env python3

import os

for files in os.listdir():
    if files.endswith(".csv"):
        # os.remove(files)
        with open(f"{files[:-4]}_score.csv", 'w', encoding="utf-8") as f:
            f.write("0")
