#include <iostream>

#include "animal.h"
#include "raymath.h"

#define RAND_WIN_POS_X static_cast<float>(GetRandomValue(0, WINDOW_WIDTH))
#define RAND_WIN_POS_Y static_cast<float>(GetRandomValue(0, WINDOW_HEIGHT))
#define RAND_0_1_FLOAT static_cast<float>(GetRandomValue(1, 100) / 100.0f)
#define RAND_0_2RAD_FLOAT static_cast<float>(GetRandomValue(0, 360) * DEG2RAD)


//create animal with position, rotation and default size
Animal::Animal() : Animal(RAND_WIN_POS_X, RAND_WIN_POS_Y, RAND_0_2RAD_FLOAT, ANIMAL_SIZE)
{
}

Animal::Animal(float x, float y, float rotation, float size) : m_body{Rectangle{x,y,size,size}}
{
    m_movement_dir = Vector2Rotate(Vector2{0, 1}, rotation);
    m_face_dir = m_movement_dir;
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
    m_body.x += m_velocity * m_movement_dir.x;
    m_body.y += m_velocity * m_movement_dir.y;
}
void Animal::update_direction()
{
    m_face_dir = Vector2Rotate(m_face_dir, m_rot_velocity);
    m_face_dir = Vector2Normalize(m_face_dir);
}
void Animal::apply_friction()
{
    m_velocity *= m_friction;
    m_rot_velocity *= m_friction;
}
void Animal::move_forward()
{
    move(m_mov_strenght);
}
void Animal::move_backward()
{
    move(-m_mov_strenght);
}
void Animal::turn_right()
{
    turn(m_rot_strenght);
}
void Animal::turn_left()
{
    turn(-m_rot_strenght);
}
void Animal::draw_animal()
{
    DrawRectanglePro(
        m_body, 
        Vector2{m_body.width / 2, m_body.height / 2}, 
        Vector2Angle(m_face_dir, Vector2Zero()) * RAD2DEG, 
        m_color
        );
}
Vector2 Animal::get_face_dir()
{
    return m_face_dir;
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
    return Vector2Angle(m_movement_dir, Vector2Zero());
}
// side length (animal is always square)
float Animal::get_size()
{
    return m_body.width;
}
Rectangle Animal::get_body()
{
    return Rectangle{m_body.x - m_body.width / 2, m_body.y - m_body.height / 2, m_body.width, m_body.height};
}
void Animal::move(float force)
{
    Vector2 applied_force_vec = Vector2Scale(m_face_dir, force / m_mass);
    Vector2 movement_force_vec = Vector2Scale(m_movement_dir, m_velocity);
    movement_force_vec = Vector2Add(movement_force_vec, applied_force_vec);
    m_movement_dir = Vector2Normalize(movement_force_vec);
    m_velocity = Vector2Length(movement_force_vec);
}
void Animal::turn(float force)
{
    m_rot_velocity += force / m_mass;
}
bool Animal::is_playable()
{
    return true;
}