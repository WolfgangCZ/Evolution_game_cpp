#include <iostream>

#include "animal.h"
#include "raymath.h"

#define RAND_WIN_POS_X static_cast<float>(GetRandomValue(0, WINDOW_WIDTH))
#define RAND_WIN_POS_Y static_cast<float>(GetRandomValue(0, WINDOW_HEIGHT))
#define RAND_0_1_FLOAT static_cast<float>(GetRandomValue(0, 1))


Animal::Animal() : 
    m_body{Rectangle{RAND_WIN_POS_X, RAND_WIN_POS_Y, ANIMAL_SIZE, ANIMAL_SIZE}}
    // create delegating constructors
{
    m_direction = Vector2(RAND_0_1_FLOAT, RAND_0_1_FLOAT);
    m_mass = m_body.height * m_body.width;
}

Animal::Animal(float x, float y, float rotation, float size) : 
    m_body{Rectangle{x,y,size,size}}
{
    m_direction = Vector2Rotate(Vector2{1, 0}, rotation);
    m_mass = m_body.height * m_body.width;
}
void Animal::update()
{
    update_direction();
    update_position();
    apply_friction();
    draw_animal();
}
void Animal::update_position()
{
    m_body.x += m_velocity * m_direction.x;
    m_body.y += m_velocity * m_direction.y;
}
void Animal::update_direction()
{
    m_direction = Vector2Rotate(m_direction, m_rot_velocity);
    m_direction = Vector2Normalize(m_direction);
}
void Animal::apply_friction()
{
    m_velocity *= animal_friction;
    m_rot_velocity *= animal_friction;
}

void Animal::draw_animal()
{
    DrawRectanglePro(
        m_body, 
        Vector2{m_body.width / 2, m_body.height / 2}, 
        Vector2Angle(m_direction, Vector2Zero()) * RAD2DEG, 
        m_color
        );
}
void Animal::modify_velocity(float force)
{
    m_velocity += force / m_mass; 
}

void Animal::modify_rot_velocity(float rot_force)
{
    m_rot_velocity += rot_force / m_mass;
}
Vector2 Animal::get_position()
{
    return Vector2{m_body.x, m_body.y};
}
float Animal::get_velocity()
{
    return m_velocity;
}
//in radians
float Animal::get_rot_angle()
{
    return Vector2Angle(m_direction, Vector2Zero());
}
// side length (animal is always square)
float Animal::get_size()
{
    return m_body.width;
}
Rectangle Animal::get_body()
{
    return m_body;
}