#include<iostream>
#include<ctime>
#include<vector>
#include<memory>

class Test
{
    public:
        Test()
        {
            std::cout << "1 constructor used" << std::endl;
        }
        Test(const Test &tmp)
        {
            std::cout << "2 copy constr used" << std::endl;
        }
        ~Test()
        {
            std::cout << "3 destructor used" << std::endl;
        }
        void print()
        {
            std::cout << "x: " << m_x << " y: " << m_y << ", adress: " << this << std::endl;
        }
        int get_x()
        {
            return m_x;
        }
        int get_y()
        {
            return m_y;
        }
                void set_x(int a)
        {
            m_x = a;
        }
        void set_y(int a)
        {
            m_y = a;
        }
    private:
        int m_x {std::rand()%100};
        int m_y {std::rand()%100};
};

struct WorldPopulation
{
    std::vector <std::shared_ptr<Test>> class_arr{};
};


int main ()
{
    WorldPopulation world;
    const std::size_t range {3};
    std::srand(time(0));
    //std::vector <std::shared_ptr<Test>> shptr_array{};
    //std::vector <std::shared_ptr<Test>> shptr_arr_x{};
    std::cout << "first filling" << std::endl;
    for(std::size_t i {0}; i<range; ++i)
    {
        world.class_arr.push_back(std::make_shared<Test>(Test{}));
        //shptr_arr_x.push_back(std::shared_ptr<Test>{shptr_array[i]});
    }
    /*
    std::cout << "second filling" << std::endl;
    for(std::size_t i {0}; i<range; ++i)
    {
        shptr_array.push_back(std::make_shared<Test>(Test{}));
    }
    */
    std::cout << "setting 2" << std::endl;
    world.class_arr[0]->set_x(5);
    world.class_arr[1]->set_x(5);
    std::cout << "printing" << std::endl;
    for(std::size_t i {0}; i<world.class_arr.size(); ++i)
    {
        std::cout << "pos: " << i << ", ";
        world.class_arr[i]->print();
    }

    std::cout << "ending properly" << std::endl;
    return 0;
}