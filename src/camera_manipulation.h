#ifndef CAMERA_MANIPULATION_H
#define CAMERA_MANIPULATION_H

#include "raylib.h"

//manipulation using mouse wheel
void mouse_cam_manipulation(Vector2 &camera_position, Vector2 &init_mouse_pos);

void cam_zooming(Camera2D &camera);
//manipulation using keyboard
void keyboard_cam_manipulation(Vector2 &camera_position); 

#endif //CAMERA_MANIPULATION_H

