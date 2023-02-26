#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include "raylib.h"

#include "camera_manipulation.h"
#include "life_form.h"


int main ()
{
    const int screen_width {800};
    const int screen_height {800};

    const int upper_bound {0};
    const int lower_bound {screen_height};
    const int left_bound {0};
    const int right_bound {screen_width};
    InitWindow(screen_height,screen_width, "New window");

    double const pi {3.1415};

    double bounciness_coef {0.8};

    double circle_x {screen_width/2};
    double circle_y {screen_height/2};

    double circle_radius {50};

    double friction {0.02};

    double circle_mass {pi*pi*circle_radius};

    //double move_force {100};

    double forward_force {0};

    double x_speed {0};
    double y_speed {0};

    double accl_x {0};
    double accl_y {0};

//setting up camera
    Vector2 camera_position {screen_width/2,screen_height/2};

    Camera2D camera {0};
    camera.target = camera_position;
    camera.offset = (Vector2){screen_width/2,screen_height/2};
    camera.rotation = 0;
    camera.zoom = 1;

    LifeForm player {};


    SetTargetFPS(60);
    while(WindowShouldClose()==false)
    {
                // Camera zoom controls

        BeginDrawing();
        ClearBackground(WHITE);
        BeginMode2D(camera);
        
        camera.target = camera_position;
        //game logic
        DrawRectangle(0, 0, screen_width, screen_height, GREEN);
        DrawRectangleRec(player.getBody(), player.getColor());

        
        Vector2 init_mouse_pos; //mouse position - tohle dát dopredele a vylepšit nelínbí se mi to
        //mouse camera manipulation
        mouse_cam_manipulation(camera_position, init_mouse_pos);
        keyboard_cam_manipulation(camera_position);
        cam_zooming(camera);

        //reseting ball
        if(IsKeyDown(KEY_X))
        {
        circle_x = screen_width/2;
        circle_y = screen_height/2;
        x_speed = 0;
        y_speed = 0;
        }

        //calculating acceleration
        accl_x = forward_force/player.getWeight();
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
        else if (lower_bound-(circle_y+circle_radius)==0) y_speed *= -1*bounciness_coef;

        forward_force = 0;
        EndMode2D();
        EndDrawing();
    }
    std::cout << "DONE! See ya ";
    return 0;
}