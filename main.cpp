#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include "raylib.h"


int main ()
{

    const int screen_width {800};
    const int screen_height {800};

    const int upper_bound {0};
    const int lower_bound {screen_height};
    const int left_bound {0};
    const int right_bound {screen_width};
    InitWindow(screen_height,screen_width, "New window");

    double const gravity {1};
    double const pi {3.1415};

    double const max_zoom {5};
    double const min_zoom {0.1};

    double bounciness_coef {0.8};
    double ground_bounciness_coef {0.2};

    double circle_x {screen_width/2};
    double circle_y {screen_height/2};

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

//setting up camera
    Vector2 camera_position {screen_width/2,screen_height/2};

    Camera2D camera {0};
    camera.target = camera_position;
    camera.offset = (Vector2){screen_width/2,screen_height/2};
    camera.rotation = 0;
    camera.zoom = 1;

    SetTargetFPS(60);
    while(WindowShouldClose()==false)
    {
                // Camera zoom controls

        BeginDrawing();
        ClearBackground(WHITE);
        BeginMode2D(camera);
        
        camera.target = camera_position;
        //game logic
        friction = 0.02;
        bool grounded {false};
        if((lower_bound-(circle_y+circle_radius))<=0) grounded = true;
        DrawRectangle(0, 0, screen_width, screen_height, GREEN);
        DrawCircle(circle_x,circle_y,circle_radius,BLUE);


        camera.zoom += ((float)GetMouseWheelMove()*0.2f);
        if(camera.zoom > max_zoom) camera.zoom = max_zoom;
        if(camera.zoom < min_zoom) camera.zoom = min_zoom;

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
        
        //mouse camera manipulation
        Vector2 init_mouse_pos;
        if(!(IsCursorOnScreen() && IsMouseButtonDown(MOUSE_BUTTON_MIDDLE))) init_mouse_pos = GetMousePosition();
        if(IsCursorOnScreen() && IsMouseButtonDown(MOUSE_BUTTON_MIDDLE))
        {
            Vector2 act_mouse_pos{(GetMousePosition())};
            camera_position.x = act_mouse_pos.x - init_mouse_pos.x;
            camera_position.y = act_mouse_pos.y - init_mouse_pos.y;
            if (camera_position.x > screen_width*2) camera_position.x = screen_width*2;
            if (camera_position.x < -screen_width) camera_position.x = -screen_width;
            if (camera_position.y > screen_width*2) camera_position.y = screen_width*2;
            if (camera_position.y < -screen_height) camera_position.y = -screen_height;
        }
        else init_mouse_pos = (Vector2){GetMousePosition()};




        //camera manipulation
        if(IsKeyDown(KEY_W))
        {
        camera_position.y -= 10;

        }
        if(IsKeyDown(KEY_S))
        {
        camera_position.y += 10;
        }

        if(IsKeyDown(KEY_A))
        {
        camera_position.x -= 10;
        }

        if(IsKeyDown(KEY_D))
        {
        camera_position.x += 10;
        }


        //brake
        if(IsKeyDown(KEY_SPACE) && grounded)
        {
        friction = 0.1;
        }
        
        if(IsKeyDown(KEY_X))
        {
        circle_x = screen_width/2;
        circle_y = screen_height/2;
        x_speed = 0;
        y_speed = 0;
        }
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
        EndMode2D();
        EndDrawing();
    }
    std::cout << "DONE! See ya ";
    return 0;
}