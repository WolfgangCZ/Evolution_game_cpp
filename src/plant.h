// #pragma once

// #include "basic_settings.h"

// class Plant : public Organism
// {   
//     private:
//         Rectangle body;
//         Color color = GREEN;
//         std::string species_name = "plant";
//     public:
//         Plant() : body{
//                 Rectangle{
//                     static_cast<float>(GetRandomValue(0, WINDOW_HEIGHT)),
//                     static_cast<float>(GetRandomValue(0, WINDOW_WIDTH)),
//                     PLANT_SIZE,
//                     PLANT_SIZE
//                 }
//         }
//         {}
//         Plant(float x, float y, float size) : body{Rectangle{x,y,size,size}}
//         {}
//         virtual void update() override
//         {
//             draw_plant();
//         }
//         void draw_plant()
//         {
//             DrawRectangleRec(body, color);
//         }
// };
