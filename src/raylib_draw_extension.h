#pragma once

#include <raylib.h>

void DrawRectCorners(Rectangle rect, int segments, Color color)
{
    DrawRectangleLinesEx(rect, segments, color);
}