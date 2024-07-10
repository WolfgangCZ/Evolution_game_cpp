#pragma once

#include <memory>

#include "entity_manager.h"
#include "animal.h"
#include "raylib.h"
#include "raylib_draw_extension.h"
#include "game_state_manager.h"

class GameApp;

class PlayerControl
{
    private:
        std::shared_ptr<Entity> m_selected_animal;
    public:
        PlayerControl();
        void update();
        void draw_select();
        void attach_to_animal(const std::shared_ptr<Entity>& animal);
        void detach_from_animal();
        const std::shared_ptr<Animal>& get_animal() const;
        void move_player();
        void rotate_player();
        void select_player();
};
