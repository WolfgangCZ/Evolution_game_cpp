#include "raylib.h"

void mouse_cam_manipulation(Vector2 &camera_position, Vector2 &init_mouse_pos)
{

    if(!(IsCursorOnScreen() && IsMouseButtonDown(MOUSE_BUTTON_MIDDLE))) init_mouse_pos = GetMousePosition();
    if(IsCursorOnScreen() && IsMouseButtonDown(MOUSE_BUTTON_MIDDLE))
    {
        Vector2 act_mouse_pos{(GetMousePosition())};
        camera_position.x += act_mouse_pos.x - init_mouse_pos.x;
        camera_position.y += act_mouse_pos.y - init_mouse_pos.y;
        //limit boundaries *2
        if (camera_position.x > GetScreenWidth()*2) camera_position.x = GetScreenWidth()*2;
        if (camera_position.x < -GetScreenWidth()) camera_position.x = -GetScreenWidth();
        if (camera_position.y > GetScreenHeight()*2) camera_position.y = GetScreenHeight()*2;
        if (camera_position.y < -GetScreenHeight()) camera_position.y = -GetScreenHeight();
    }
    else init_mouse_pos = (Vector2){GetMousePosition()};
}

void cam_zooming(Camera2D &camera)
{
    double const max_zoom {5};
    double const min_zoom {0.1};
    camera.zoom += ((float)GetMouseWheelMove()*0.2f);
    if(camera.zoom > max_zoom) camera.zoom = max_zoom;
    if(camera.zoom < min_zoom) camera.zoom = min_zoom;
}

void keyboard_cam_manipulation(Vector2 &camera_position)
{
        if(IsKeyDown(KEY_UP)) camera_position.y -= 10;
        if(IsKeyDown(KEY_DOWN)) camera_position.y += 10;
        if(IsKeyDown(KEY_LEFT)) camera_position.x -= 10;
        if(IsKeyDown(KEY_RIGHT)) camera_position.x += 10;
}