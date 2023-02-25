#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include "raylib.h"

int main ()
{
    const int w_width {600};
    const int w_height {600};

    const int upper_bound {0};
    const int lower_bound {w_height};
    const int left_bound {0};
    const int right_bound {w_width};
    InitWindow(w_height,w_width, "New window");

    double const gravity {1};
    double const pi {3.1415};

    double bounciness_coef {0.8};
    double ground_bounciness_coef {0.2};

    double circle_x {w_width/2};
    double circle_y {w_height/2};

    double circle_radius {50};

    double friction {0.00};

    double circle_mass {pi*pi*circle_radius};

    double move_force {100};
    double jump_force {15000};

    double x_force {0};
    double y_force {0};

    double x_speed {0};
    double y_speed {0};

    double accl_x {0};
    double accl_y {0};

    SetTargetFPS(60);
    while(WindowShouldClose()==false)
    {
        
        BeginDrawing();
        ClearBackground(WHITE);
        //game logic
        friction = 0.02;
        bool grounded {false};
        if((lower_bound-(circle_y+circle_radius))<=0) grounded = true;
        DrawCircle(circle_x,circle_y,circle_radius,BLUE);

        if(IsKeyDown(KEY_UP) && grounded)
        {
        y_force -= jump_force;

        }
        if(IsKeyDown(KEY_DOWN))
        {
        y_force += move_force;
        }

        if(IsKeyDown(KEY_LEFT))
        {
        x_force -= move_force;
        }

        if(IsKeyDown(KEY_RIGHT))
        {
        x_force += move_force;
        }

        //brake
        if(IsKeyDown(KEY_SPACE) && grounded)
        {
        friction = 0.1;
        }
        
        if(IsKeyDown(KEY_X))
        {
        circle_x = w_width/2;
        circle_y = w_height/2;
        x_speed = 0;
        y_speed = 0;
        }
        //calculating acceleration
        //calculating acceleration

        accl_x = x_force/circle_mass;
        if(grounded) accl_y = y_force/circle_mass;
        else accl_y = y_force/circle_mass+gravity;

        x_speed = accl_x + x_speed;
        y_speed = accl_y + y_speed;



        //moving
        circle_x += x_speed;
        circle_y += y_speed;
        //friction
        x_speed -= x_speed*friction;
        y_speed -= y_speed*friction;

        //boundary cap (doesnt really work properly on high speeds)
        if(circle_x+circle_radius > right_bound) circle_x = right_bound-circle_radius;
        else if(circle_x-circle_radius < left_bound) circle_x = left_bound+circle_radius;
        else if(circle_y-circle_radius < upper_bound) circle_y = upper_bound+circle_radius;
        else if(circle_y+circle_radius > lower_bound) circle_y = lower_bound-circle_radius;

        //boundary bounce
        if(((circle_x-circle_radius)-left_bound)==0) x_speed *= -1*bounciness_coef;
        else if (right_bound-(circle_x+circle_radius)==0) x_speed *= -1*bounciness_coef;
        else if(((circle_y-circle_radius)-upper_bound)==0) y_speed *= -1*bounciness_coef;
        else if (lower_bound-(circle_y+circle_radius)==0) y_speed *= -1*ground_bounciness_coef;

        x_force = 0;
        y_force = 0;


Rectangle rectangle1 {1,2,3,4};

        //end of game logic

        EndDrawing();
    }
    std::cout << "DONE! See ya ";
    return 0;
}