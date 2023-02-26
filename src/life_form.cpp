#include "raylib.h"
#include "life_form.h"

unsigned int LifeForm::lf_count = 0;

Rectangle LifeForm::getBody()
{
    return Rectangle{position_x, position_y, body_size, body_size};
}

void LifeForm::drawBody()
{
    DrawRectangle(position_x, position_y, body_size, body_size, lf_color);
}

Vector2 LifeForm::getPos()
{
    return Vector2{position_x, position_y};
}

Color LifeForm::getColor()
{
    return lf_color;
}

float LifeForm::getWeight()
{
    return body_size*body_size;
}

void LifeForm::head_angle(float rotation)
{
    lf_head_angle += rotation;
}