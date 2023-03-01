#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include "raylib.h"

#include "world.h"
#include "camera_manipulation.h"
#include "life_form.h"
#include "utilities.h"
#include "body_structure.h"
#include "physics_model.h"
#include "keyboard.h"


int main ()
{
    WorldPopulation all_animals{};
    LifeForm *ptr {nullptr};
    const int screen_width {800};
    const int screen_height {800};

    int text_row[]{120,140,160,180,200,220,240,260,280,300};
    /*
    const int upper_bound {0};
    const int lower_bound {screen_height};
    const int left_bound {0};
    const int right_bound {screen_width};
    */
    InitWindow(screen_height,screen_width, "New window");

    //float bounciness_coef {0.8f};
    float friction {0.05f};

    //double move_force {100};

    float forward_force {0};
    float rotation_force {0};

//setting up camera
    Vector2 camera_position {screen_width/2,screen_height/2};

    Camera2D camera {0};
    camera.target = camera_position;
    camera.offset = (Vector2){screen_width/2,screen_height/2};
    camera.rotation = 0;
    camera.zoom = 1;

    Animal player {};


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
        
        Vector2 init_mouse_pos; //mouse position - tohle dát dopredele a vylepšit nelínbí se mi to
        //mouse camera manipulation
        mouse_cam_manipulation(camera_position, init_mouse_pos);
        keyboard_cam_manipulation(camera_position);
        cam_zooming(camera);

        //reseting ball
        if(IsKeyDown(KEY_X))
        {
            player.structure.set_x(screen_width/2);
            player.structure.set_y(screen_height/2);
            player.physics.set_velocity(0,0);
        }

        keyboard_controls(forward_force, rotation_force, all_animals);

        //calculating acceleration
        player.physics.set_acc(forward_force, player.structure.get_weight());
        player.physics.set_rot_acc(rotation_force, player.structure.get_weight());

        player.physics.add_velocity(player.physics.get_acc());
        player.physics.add_rot_velocity(player.physics.get_rot_acc());



        //moving
        player.update_movement();
        player.update_rotation();
        player.update_draw(); //tady někde bude chyba
        all_animals.draw_animals(ptr);
        all_animals.update_animals_movement(ptr);
        all_animals.update_rotation_movement(ptr);

        //friction
        player.physics.add_velocity(friction_calc(friction,player.physics.get_velocity())); //friction
        player.physics.add_rot_velocity(friction_calc(friction,player.physics.get_rot_velocity())); //friction
/*
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

*/      
        DrawText(TextFormat("Obj. velocity: %04.02f p/s", player.physics.get_velocity()*60), 100, text_row[0], 15, BLACK);
        DrawText(TextFormat("Rot. velocity: %04.02f ", player.physics.get_rot_velocity()*60*180/PI), 100, text_row[1], 15, BLACK);
        DrawText(TextFormat("Forward force: %03i", forward_force), 100, text_row[2], 15, BLACK);
        DrawText(TextFormat("Rotation force: %03i", rotation_force), 100, text_row[3], 15, BLACK);
        DrawText(TextFormat("Elapsed Time: %02.02f ms", GetTime()), 100, text_row[4], 15, BLACK);
        DrawText(TextFormat("FPS: %03i", GetFPS()), 100, text_row[5], 15, BLACK);
        DrawText(TextFormat("X pos: %02.02f", player.structure.get_centre_x()), 100, text_row[6], 15, BLACK);
        DrawText(TextFormat("Y pos: %02.02f", player.structure.get_centre_y()), 100, text_row[7], 15, BLACK);
        DrawText(TextFormat("Y pos: %02i", player.get_animal_count()), 100, text_row[8], 15, BLACK);

        forward_force = 0;
        rotation_force = 0;
        EndMode2D();
        EndDrawing();
    }
    std::cout << "DONE! See ya ";
    return 0;
}
