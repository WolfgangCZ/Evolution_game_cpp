#ifndef BODY_STRUCTURE_H
#define BODY_STRUCTURE_H
#include "raylib.h"
#include <cassert>
#include <iostream>

/*
body structure defines all the physical objects on named animal, plant, resource or obstacle and dimensional properties (like position and rotation)
members:
    - m_position = position x,y as vector2 
    - m_size = one size of rectanhle (default 20)
    - m_weight = area of rectangle
    - m_color = color of rectangle (its gonna serve as classification of its purpose or characteristics in future)
functions serve as movement and rotation tools and also as modifying these things (self explanatory)
*/

class BodyStructure
{
        public:
        BodyStructure()
        {
            if(m_weight == 0)
            {
                assert(true);
                std::cout << "assertion failed - weight cannot be 0!!!" << std::endl;
            }
        }
        ~BodyStructure()
        {}

        //getters
        Rectangle get_rectangle();  //get rectangle obj of this structure
        Rectangle get_centered_rect(); //get rectangle with pos in center
        Vector2 get_position();     //get base position of rectangle as vector2 (which is left upper corner for some reason)
        float get_x();              //get x of base position of rectangle
        float get_y();              //get x of base position of rectangle
        Vector2 get_centre_pos();   //get centre position of rectangle as vector2
        float get_centre_x();       //get x of centre of mass of rectangle
        float get_centre_y();       //get y of centre of mass of rectangle
        float get_weight();         //get weight (which is just area of rectangle)
        float get_size();           //get size
        Color get_color();          //get color as object

        //setters               
        void set_x(float x);        //set base x position of rectangle
        void set_y(float y);        //set base y position of rectangle
        void set_centre_x (float x);    //set centre x position of rectangle
        void set_centre_y (float y);    //set centre x position of rectangle

        //adders
        void add_x(float add_x);        //adder to x position
        void add_y(float add_y);        //adder to y position

        //functions


        protected:
        Vector2 position                //vector obj of starting position (defined as random on map)
            {
            static_cast<float>(GetRandomValue(0,GetScreenHeight())),
            static_cast<float>(GetRandomValue(0,GetScreenHeight()))
            };
        float m_size {20};                //size of rectangle
        Color m_color{BLUE};            //color as object 
        float m_weight = m_size*m_size;       //weight which is just area of rectangle
};

#endif //BODY_STRUCTURE_H