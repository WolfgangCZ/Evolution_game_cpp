#include "body_structure.h"
#include "utilities.h"
#include "raylib.h"

Rectangle BodyStructure::get_rectangle()
{
    return Rectangle{position.x, position.y, size, size};
}
Rectangle BodyStructure::get_centered_rect()
{
    return Rectangle{get_centre_x(), get_centre_y(), size, size};
}
Vector2 BodyStructure::get_position()
{
    return Vector2{position.x, position.y};
}

float BodyStructure::get_x()
{
    return position.x;
}
float BodyStructure::get_y()
{
    return position.y;
}
Vector2 BodyStructure::get_centre_pos()
{
    return Vector2{position.x + size/2, position.y + size/2};
}
float BodyStructure::get_centre_x()
{
    return position.x + size/2;
}
float BodyStructure::get_centre_y()
{
    return position.y + size/2;
}

void BodyStructure::set_x(float x)
{
    position.x = x;
}

void BodyStructure::set_y(float y)
{
    position.y = y;
}
void BodyStructure::set_centre_x (float x)
{
    position.x = x+size/2;
}
void BodyStructure::set_centre_y (float y)
{
    position.y = y+size/2;
}

void BodyStructure::add_x(float add_x)
{
    position.x += add_x;
}
void BodyStructure::add_y(float add_y)
{
    position.y += add_y;
}

float BodyStructure::get_weight()
{
    return weight;
}
float BodyStructure::get_size()
{
    return size;
}

Color BodyStructure::get_color()
{
    return m_color;
}


