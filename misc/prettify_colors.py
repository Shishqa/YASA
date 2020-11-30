#!/usr/bin/python3

import re
import sys

good_text = []

text = sys.stdin.readlines()

for line in text:
    line = re.split(r"\W+", line)
    line[0] = re.sub(r'(?<!^)(?=[A-Z])', '_', line[0]).upper()
    print("#define %-25s {%3s, %3s, %3s, 255}" %
            (line[0], line[2], line[3], line[4]))
