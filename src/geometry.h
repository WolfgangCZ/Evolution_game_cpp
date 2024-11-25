#pragma once

#include "../include/raylib.h"
#include "../include/raymath.h"
#include <math.h>

inline Vector2 Vector2Reduce(Vector2 v, float reduce)
{
    Vector2 result = { v.x/reduce, v.y/reduce };

    return result;
}

