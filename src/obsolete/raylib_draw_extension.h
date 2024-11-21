#pragma once

#include "raylib.h"

void DrawRectCorners(Rectangle rect, float line_thick, float corner_radius, Color color)
{
    Vector2 lu_corner = Vector2{rect.x, rect.y};
    Vector2 ru_corner = Vector2{rect.x + rect.width, rect.y};
    Vector2 ld_corner = Vector2{rect.x, rect.y + rect.height};
    Vector2 rd_corner = Vector2{rect.x + rect.width, rect.y + rect.height};
    DrawLineEx(lu_corner, Vector2{lu_corner.x + corner_radius , lu_corner.y}, line_thick, color);
    DrawLineEx(ru_corner, Vector2{ru_corner.x - corner_radius, ru_corner.y}, line_thick, color);
    DrawLineEx(ld_corner, Vector2{ld_corner.x + corner_radius , ld_corner.y}, line_thick, color);
    DrawLineEx(rd_corner, Vector2{rd_corner.x - corner_radius, rd_corner.y}, line_thick, color);
    DrawLineEx(lu_corner, Vector2{lu_corner.x, lu_corner.y + corner_radius}, line_thick, color);
    DrawLineEx(ru_corner, Vector2{ru_corner.x, ru_corner.y + corner_radius}, line_thick, color);
    DrawLineEx(ld_corner, Vector2{ld_corner.x, ld_corner.y - corner_radius}, line_thick, color);
    DrawLineEx(rd_corner, Vector2{rd_corner.x, rd_corner.y - corner_radius}, line_thick, color);
}