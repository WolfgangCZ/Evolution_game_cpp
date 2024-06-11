#include <format>
#include <cstring>

#include "raylib.h"
#include "animal_control.h"
#include "basic_settings.h"

class DebugMode
{
    public:
        // by pressing F3 the debug mode will be toggled
        void activate()
        {
            if (IsKeyPressed(KEY_F3))
            {
                if(m_debug_mode) 
                    m_debug_mode = 0;
                else 
                    m_debug_mode = 1;
            }
            reset();
        }
        void show_player_info(AnimalControl &player_control)
        {
            if (!m_debug_mode) return;
            if (player_control.get_animal() == nullptr) return;

            Vector2 player_pos = player_control.get_animal()->get_position();
            float player_vel = player_control.get_animal()->get_velocity();
            float player_rot_angle = player_control.get_animal()->get_rot_angle() * RAD2DEG;
            DrawText("DEBUG EVOGAME", left_pad, _grab_new_line(), m_text_size, WHITE);
            DrawText(_float_label("Pos X", player_pos.x).c_str(), left_pad, _grab_new_line(), m_text_size, WHITE);
            DrawText(_float_label("Pos Y", player_pos.y).c_str(), left_pad, _grab_new_line(), m_text_size, WHITE);
            DrawText(_float_label("Velocity", player_vel).c_str(), left_pad, _grab_new_line(), m_text_size, WHITE);
            DrawText(_int_label("Angle", player_rot_angle).c_str(), left_pad, _grab_new_line(), m_text_size, WHITE);
        }
        void show_population_info(AnimalBuffer &population)
        {
            if (!m_debug_mode) return;
            DrawText(_int_label("Animals", (int)population.get_population().size()).c_str(), left_pad, _grab_new_line(), m_text_size, WHITE);
        }
        void show_geometry(AnimalControl &player_control)
        {
            if (!m_debug_mode) return;
            if (player_control.get_animal() == nullptr) return;

            Vector2 player_pos = player_control.get_animal()->get_position();
            Vector2 center = {WINDOW_WIDTH/2, WINDOW_HEIGHT/2};
            DrawCircle(center.x, center.y, 2, GREEN);
            DrawLine(center.x, center.y, player_pos.x, player_pos.y, GREEN);
        }
        void reset()
        {
            m_displayed_lines = 0;
        }

    private:
        Color color = WHITE;
        bool m_debug_mode = false;
        float left_pad = 10.0f;
        float m_text_size = 20.0f;
        float top_pad = 10.0f;
        int m_displayed_lines = 0;

        std::string _float_label(std::string label, float value)
        {
            return std::format("{}: {:.2f}", label, value);
        }
        std::string _int_label(std::string label, int value)
        {
            return std::format("{}: {}", label, value);
        }
        float _grab_new_line()
        {
            m_displayed_lines += 1;
            return top_pad + m_text_size * m_displayed_lines;
        }
};