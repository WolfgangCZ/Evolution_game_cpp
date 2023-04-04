#include<iostream>
#include<ctime>
#include<vector>
#include<memory>

/*
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

struct TestArray
{
    std::vector <std::shared_ptr<Test>> class_arr{};
};


int main ()
{
    TestArray test_array;
    const std::size_t range {3};
    std::srand(time(0));

    std::cout << "first filling" << std::endl;
    for(std::size_t i {0}; i<range; ++i)
    {
        test_array.class_arr.push_back(std::make_shared<Test>(Test{}));

    }

    std::cout << "setting 2" << std::endl;
    test_array.class_arr[0]->set_x(5);
    test_array.class_arr[1]->set_x(5);
    std::cout << "printing" << std::endl;
    for(std::size_t i {0}; i<test_array.class_arr.size(); ++i)
    {
        std::cout << "pos: " << i << ", ";
        test_array.class_arr[i]->print();
    }
    for(std::size_t i {0}; i<range; ++i)
    {
        test_array.class_arr.erase(test_array.class_arr.begin()+i);
    }
    

    std::cout << "ending properly" << std::endl;
    return 0;
}

*/


int some_func(int a)
{
    std::cout << "inside function" << std::endl;
    switch(a)
    {
        case 1 : return 10;
        break;
        case 2 : return 20;
        break;
        default : return 30;
        break;
    }
}

int main ()
{
    
    std::cout << "some func result " << some_func(1);
    return 0;
}