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

/*
WHAT TO ADD:
function for text drawing
function for player movement (to clean things up a little)
somehow improve camera manipulation to clean those lines of code

*/

int main ()
{
    WorldPopulation all_animals{};
    LifeForm *ptr {nullptr};
    const int screen_width {800};
    const int screen_height {800};

    //some parameters for drawing text at the end
    int text_row[]{120,140,160,180,200,220,240,260,280,300};
    int text_column {100};
    int text_size {15};

    InitWindow(screen_height,screen_width, "New window");

    float friction {0.05f};

    //forward and rotation force set to 0, modifying on the run based on inputs
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
        //-------------------------------------------------------------------------------
        //GAME LOGIC
        //-------------------------------------------------------------------------------

        // Camera zoom controls
        BeginDrawing();
        ClearBackground(WHITE);
        BeginMode2D(camera);
        
        camera.target = camera_position;
        DrawRectangle(0, 0, screen_width, screen_height, GREEN);
        //mouse position - get rid of this cause camera manipulation by using mouse wheel is wonky as fuck
        Vector2 init_mouse_pos;


        //mouse camera manipulation
        mouse_cam_manipulation(camera_position, init_mouse_pos);
        keyboard_cam_manipulation(camera_position);
        cam_zooming(camera);

        //reseting player obj to center of screen (angle conserved)
        if(IsKeyDown(KEY_X))
        {
            player.structure.set_x(screen_width/2);
            player.structure.set_y(screen_height/2);
            player.physics.set_velocity(0,0);
        }

        //make it BETTER!!!!!!!! SOMEHOW
        keyboard_controls(forward_force, rotation_force, all_animals); 

        //calculating acceleration for player obj
        player.physics.set_acc(forward_force, player.structure.get_weight());
        player.physics.set_rot_acc(rotation_force, player.structure.get_weight());
        //by passing acceleration we get velocity for player obj
        player.physics.add_velocity(player.physics.get_acc());
        player.physics.add_rot_velocity(player.physics.get_rot_acc());

        //moving player (can be shrinked to one function i guess)
        player.update_movement();
        player.update_rotation();
        player.update_draw();

        //moving population (can be shrinked to one function i guess)
        all_animals.draw_animals(ptr);
        all_animals.update_animals_movement(ptr);
        all_animals.update_rotation_movement(ptr);

        //friction for player
        player.physics.add_velocity(friction_calc(friction,player.physics.get_velocity())); //friction
        player.physics.add_rot_velocity(friction_calc(friction,player.physics.get_rot_velocity())); //friction
/*
        //function for bouncing of boundaries, doesnt really work now when i made player obj
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
        

        //-------------------------------------------------------------------------------
        //GAME LOGIC END
        //-------------------------------------------------------------------------------
        //draw parameters of player (self explaantory in descrition for each draw)
        DrawText(TextFormat("Obj. velocity: %04.02f p/s", player.physics.get_velocity()*60), text_column, text_row[0], text_size, BLACK);
        DrawText(TextFormat("Rot. velocity: %04.02f ", rads_to_degrees(player.physics.get_rot_velocity())*60), text_column, text_row[1], text_size, BLACK);
        DrawText(TextFormat("Forward force: %03i", forward_force), text_column, text_row[2], text_size, BLACK);
        DrawText(TextFormat("Rotation force: %03i", rotation_force), text_column, text_row[3], text_size, BLACK);
        DrawText(TextFormat("Elapsed Time: %02.02f ms", GetTime()), text_column, text_row[4], text_size, BLACK);
        DrawText(TextFormat("FPS: %03i", GetFPS()), text_column, text_row[5], 15, BLACK);
        DrawText(TextFormat("X pos: %02.02f", player.structure.get_centre_x()), text_column, text_row[6], text_size, BLACK);
        DrawText(TextFormat("Y pos: %02.02f", player.structure.get_centre_y()), text_column, text_row[7], text_size, BLACK);
        DrawText(TextFormat("non player animal count: %02i", all_animals.world_animals.size()), text_column, text_row[8], text_size, BLACK);
        DrawText(TextFormat("rotation: %02.02f", rads_to_degrees(player.physics.get_direction())), text_column, text_row[9], text_size, BLACK);


        forward_force = 0;
        rotation_force = 0;
        EndMode2D();
        EndDrawing();
    }
    std::cout << "DONE! See ya ";
    return 0;
}
