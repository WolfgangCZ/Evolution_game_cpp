#pragma once

#include <memory>
#include <deque>

#include "animal.h"
#include "raylib.h"
#include "game_state.h"

enum KeyboardEvent
{
    EVENT_KEY_UP,
    EVENT_KEY_DOWN,
    EVENT_KEY_LEFT,
    EVENT_KEY_RIGHT,
    EVENT_KEY_C,
    EVENT_KEY_D,
    EVENT_KEY_F3,
};

class EventListener
{

    public:
        EventListener(const GameStateHandler &game_state_handler)
            : m_game_state_handler(game_state_handler)
        {}
    private:
        std::deque<KeyboardEvent> m_keyboard_events;
        const GameStateHandler &m_game_state_handler;
};