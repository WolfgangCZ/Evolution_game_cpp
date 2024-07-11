#include "animal.h"

class AnimalFactory
{
    public:
        AnimalFactory();
        static std::shared_ptr<Animal> create_basic_animal();
    private:
        float m_size = 20;
        float m_mov_strength = 10;
        float m_rot_strength = 1;
        float m_friction = 0.9;
};

AnimalFactory::AnimalFactory()
{
}

std::shared_ptr<Animal> AnimalFactory::create_basic_animal()
{
    return std::make_shared<Animal>(RAND_WIN_POS_X, RAND_WIN_POS_Y, RAND_0_2RAD_FLOAT, m_size);
}