#ifndef LIFE_FORM_H
#define LIFE_FORM_H
#include "raylib.h"

class LifeForm
{
    public:
    static unsigned int lf_count;

    LifeForm()
    {
        lf_count++;
    }
    ~LifeForm()
    {
        lf_count--;
    }

    //getters
    Rectangle getBody();
    void drawBody();
    Vector2 getPos();
    Color getColor();
    float getWeight();

    //setters
    void head_angle(float rotation);

    protected:
    float body_size {10.0f};
    float position_x {static_cast<float>(GetRandomValue(0,GetScreenWidth()))};
    float position_y {static_cast<float>(GetRandomValue(0,GetScreenHeight()))};
    unsigned int lifeID {lf_count};
    //float health {50};
    float lf_head_angle {0.0f};
    Color lf_color {RED};
};

#endif //LIFE_FORM_H

