#pragma once

#include "raylib.h"

class Entity
{
    public:
        int id = 0;
        virtual void update() = 0; 
        virtual bool is_playable() = 0;
        virtual Rectangle get_body() = 0;
};