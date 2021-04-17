#!/usr/bin/env python3

import sys
from math import *

top_right   = (9, 51)
bot_left    = (8, 50)

heights = []

def map(lon, lat):
    x = 3600 * (lon - 8)
    y = 3601 - (3600 * (lat - 50))
    return (int(x), int(y))

def get_height(x, y):
    return heights[y * 3601 + x]

coords = []
for line in sys.stdin:
    coords.append([float(x) for x in line.split(' ')])

with open('height.hgt', 'rb') as file:
    while True:
        higher  = file.read(1)
        lower   = file.read(1)

        if higher == b'' or lower == b'':
            break

        height  = lower[0] | (higher[0] << 8)
        heights.append(height)

if len(coords) > 1:
    for i in range(len(coords) - 1):
        (cx, cy)    = map(coords[i][0], coords[i][1])
        (nx, ny)    = map(coords[i + 1][0], coords[i + 1][1])

        x = cx
        y = cy

        dx = (nx - cx)
        dy = (ny - cy)

        steps = int(sqrt(dx * dx + dy + dy) * 0.5)
        for i in range(steps):
            hgt = get_height(x, y)
            print(hgt, end = ' ')

            x = int(cx + (dx / steps) * i)
            y = int(cy + (dy / steps) * i)

elif len(coords) == 1:
    (x, y)  = map(coords[0][0], coords[0][1])
    hgt = get_height(x, y)
