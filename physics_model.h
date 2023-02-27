#ifndef PHYSICS_MODEL_H
#define PHYSICS_MODEL_H
#include "raylib.h"

//class for calculating velocity of object, acceleration, rotation velocity
// rotation acceleration and angle (direction 0 north clockwise+ in rads)

class PhysicsModel
{
    public:
        PhysicsModel()
        {}
        ~PhysicsModel()
        {}
        //getters
        float get_velocity();
        float get_direction();
        float get_rot_velocity();
        float get_acc();
        float get_rot_acc();

        //setters
        //setting by exact number or force * weight
        void set_velocity(float velocity);
        void set_velocity(float x, float y);

        void set_direction(float angle);
        void set_direction(float x, float y);

        void set_acc(float acceleration);
        void set_acc(float force, float weight);
        
        void set_rot_velocity(float rot_velocity);      
        void set_rot_acc(float rot_acc);
        void set_rot_acc(float rot_force, float weight);

        //adders-substractors
        void add_velocity(float velocity);
        void add_direction(float angle);
        void add_rot_velocity(float rot_velocity);

        //functions

    protected:
        float m_direction {0}; //facing up, rad
        float m_velocity {0};
        float m_rot_velocity {0};
        float m_acceleration {0};
        float m_rot_acc{0};
};

#endif //PHYSICS_MODEL_H