#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

class AnimAttr
{
    public:
        AnimAttr()
        {}
        ~AnimAttr()
        {}
    private:
        int move_strenght {50};
        int rot_strenght {1};
        float health {100};
        float age {0};
        float energy {0};
};

class PlantAttr
{
    public:
        PlantAttr()
        {}
        ~PlantAttr()
        {}
    private:
        float health {100};
        float growth {100};
};




#endif //ATTRIBUTES_H