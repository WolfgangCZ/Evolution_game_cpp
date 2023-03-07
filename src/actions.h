#ifndef ACTIONS_H
#define ACTIONS_H

/*
class of all actions possible with array of said functions
each action when called perform said action in lifeform:animal
*/

class Actions
{
    public:
    //number [0] - move forward-backward
    int action_move();
    //number [1] - move rotate right(+) or left (-)
    int action_rotate();
    //number [2] - eat if food is in range
    int action_eat();
    //number [3] - do nothing
    int action_wait();
    //int action_duplicate();
    protected:
    int arr[4]
    {
        action_move(),
        action_rotate(),
        action_eat(),
        action_wait()
    };
};

#endif //ACTIONS_H