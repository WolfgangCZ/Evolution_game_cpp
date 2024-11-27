#pragma once

#include "../config.h"

namespace wEng
{
    struct Settings
    {
        int sub_steps = 1;
    };
    const static Settings settings = Settings();
}