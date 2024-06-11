#pragma once

#include <memory>
#include <deque>

#include "animal.h"
#include "raylib.h"
#include "game_state.h"

enum UserInputEvent
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
    private:
        std::deque<UserInputEvent> m_keyboard_events;

    public:
        EventListener()
        {
        }
};