#include "player_control.h"

PlayerControl::PlayerControl(GameApp *game)
    : m_game_app(game)
{   
}
void PlayerControl::update()
{
    select_player();
    if (!m_selected_animal) return;
    draw_select();
    move_player();
    rotate_player();
}
void PlayerControl::draw_select()
{
    const Rectangle& rect = m_selected_animal->get_body();
    float size = rect.height;
    Rectangle draw_rect = {rect.x - size / 2, rect.y - size / 2, 2*size, 2*size};
    DrawRectCorners(draw_rect, 1, draw_rect.width/4, WHITE);
}
void PlayerControl::attach_to_animal(const std::shared_ptr<Entity>& animal)
{
    m_selected_animal = animal;
}
void PlayerControl::detach_from_animal()
{
    m_selected_animal.reset();
}
void PlayerControl::move_player()
{
    if (m_game_app->game_state_manager->get_game_state() != GameState::GAME_STATE_PLAYING) return;

    if (IsKeyDown(KEY_UP))
    {
        m_selected_animal->move_forward();
    }
    if (IsKeyDown(KEY_DOWN))
    {
        m_selected_animal->move_backward();
    }
}
void PlayerControl::rotate_player()
{
    if (m_game_state_manager->get_game_state() != GameState::GAME_STATE_PLAYING) return;

    if (IsKeyDown(KEY_LEFT))
    {
        m_selected_animal->turn_left();
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        m_selected_animal->turn_right();
    }
}
void PlayerControl::select_player()
{
    if (!IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) return;

    Vector2 mouse_pos = GetMousePosition();
    // rework get all animals
    std::vector<std::shared_ptr<Entity>> entities = m_entity_manager->get_all_entities();
    for (size_t i = 0; i < m_entity_manager->get_all_entities().size(); i++)
    {
        Rectangle& body = entities[i]->get_body();
        if (CheckCollisionPointRec(mouse_pos, body) && m_selected_animal->is_playable())
        {
            detach_from_animal();
            attach_to_animal(entities[i]);
            break;
        }
    }
}

/*
psuedocode: 
function control(game_state, control_map) -> map = {key: callback}

control would automaticaly check game_state and evaluate callbacks

example:
std::unordered_map<UserInputEvent, std::function<void()>> animal_movement_control = {
    {UserInputEvent::UP, std::bind(&Animal::move_forward, m_selected_animal.get())},
    {UserInputEvent::DOWN, std::bind(&Animal::move_backward, m_selected_animal.get())},
    {UserInputEvent::LEFT, std::bind(&Animal::turn_left, m_selected_animal.get())},
    {UserInputEvent::RIGHT, std::bind(&Animal::turn_right, m_selected_animal.get())}
};
class Control
{
    Control(){};

    void control(UserInputEvent game_state, std::unordered_map<UserInputEvent, std::function<void()>> control_map)
    {
        if (game_state_handler.get_game_state() == game_state)
        {
            if (control_map.find(user_input) != control_map.end())
            {
                control_map[user_input]();
            }
        }
    }

};
*/ 