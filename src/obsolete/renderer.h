#pragma once

#include <memory>
#include <vector>

#include "entity.h"
#include "../include/raylib.h"
#include "custom_types.h"

class Renderer
{
    public:
        void render(const sh_ptr<Entity> &entity);

        void render(const std::vector<sh_ptr<Entity>> &all_entities);
};
