#include <iostream>

#include "animal.h"
#include "raymath.h"

#define RAND_DIR static_cast<float>(GetRandomValue(0, 1))
#define RAND_WIN_POS_X static_cast<float>(GetRandomValue(0, WINDOW_WIDTH))
#define RAND_WIN_POS_Y static_cast<float>(GetRandomValue(0, WINDOW_HEIGHT))
#define DEG_TO_RAD(x) ((x) * (PI / 180.0f))
#define RAD_TO_DEG(x) ((x) * (180.0f / PI))

Animal::Animal() : 
    m_body{Rectangle{RAND_WIN_POS_X, RAND_WIN_POS_Y, ANIMAL_SIZE, ANIMAL_SIZE}}, 
    m_rot_angle{static_cast<float>(GetRandomValue(0, 1))}
{
    m_mass = m_body.height * m_body.width;
}

Animal::Animal(float x, float y, float rotation, float size) : 
    m_body{Rectangle{x,y,size,size}}, m_rot_angle{rotation}
{
    m_mass = m_body.height * m_body.width;
}
void Animal::update()
{
    update_position();
    update_direction();
    apply_friction();
    draw_animal();
}
void Animal::update_position()
{
    m_body.x += m_velocity * m_direction.x;
    m_body.y += m_velocity * m_direction.y;

    std::cout << "x: " << m_body.x << " y: " << m_body.y << std::endl;

}
void Animal::update_direction()
{
    m_rot_angle += m_rot_velocity;
    std::cout << "m_rot_angle: " << m_rot_angle << std::endl;

    m_direction.x = std::sin(m_rot_angle);
    m_direction.y = std::cos(m_rot_angle);

    m_direction = Vector2Normalize(m_direction);
}
void Animal::apply_friction()
{
    m_velocity *= animal_friction;
    m_rot_velocity *= animal_friction;
}

void Animal::draw_animal()
{
    DrawRectanglePro(m_body, Vector2{0, 0}, m_rot_angle, m_color);
}
void Animal::modify_velocity(float force)
{

    m_velocity += force / m_mass; 

    std::cout << "m_velocity: " << m_velocity << std::endl;
}

void Animal::modify_rot_velocity(float rot_force)
{
    m_rot_velocity += rot_force / m_mass;

    std::cout << "m_rot_velocity: " << m_rot_velocity << std::endl;

}
Vector2 Animal::get_position()
{
    return Vector2{m_body.x, m_body.y};
}
float Animal::get_velocity()
{
    return m_velocity;
}
float Animal::get_rot_angle()
{
    return m_rot_angle;
}