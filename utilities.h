#ifndef UTILITIES_H
#define UTILITIES_H

//compute x and y value from orto value lenght and angle
float calculate_x_from_orto(float lenght, float angle_rads);
float calculate_y_from_orto(float lenght, float angle_rads);
float calculate_from_orto(float lenght, float angle);
float calculate_from_orto(float lenght, float angle);
float calculate_orto_lenght(float x, float y);
float calculate_angle_xy(float x, float y);

float friction_calc(float friction, float velocity);

#endif //UTILITES_H