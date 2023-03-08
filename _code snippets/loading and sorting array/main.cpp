#include<iostream>
#include<ctime>
#include<vector>
#include<memory>

class Test
{
    public:
    Test()
    {
        //std::cout << "1 constructor used" << std::endl;
    }
    Test(const Test &tmp)
    {
        //std::cout << "2 copy constr used" << std::endl;
    }
    ~Test()
    {
        //std::cout << "3 destructor used" << std::endl;
    }
    void print()
    {
        std::cout << "x: " << m_x << " y: " << m_y << std::endl;
    }
    int get_x()
    {
        return m_x;
    }
    int get_y()
    {
        return m_y;
    }

    private:
    int m_x {std::rand()%100};
    int m_y {std::rand()%100};
};

int main ()
{
    const std::size_t range {3000};
    std::srand(time(0));
    int count {0};
    //std::shared_ptr<Test> ptr_test = std::make_shared<Test>(Test {});
    


    std::vector <Test> class_array{};
    std::vector <Test*> ptr_array{};
    std::vector <std::shared_ptr<Test>> shptr_array{};
    //fill up the array
    for(std::size_t i {0}; i<range; ++i)
    {
        class_array.push_back(Test{});
        shptr_array.push_back(std::make_shared<Test>(class_array[i]));
    }

    std::cout << "before sorting" << std::endl;
    for(std::size_t i {0}; i<range; ++i)
    {
        shptr_array[i]->print();
    }

    int iter_count {0};
    while(true)
    {
        iter_count++;
        Test *temp_ptr = nullptr;
        std::shared_ptr<Test> temp_shptr;
        
        for(std::size_t i {1}; i<range; ++i)
        {
            if(shptr_array[i]->get_x() <  shptr_array[i-1]->get_x())
            {
                temp_shptr = shptr_array[i];
                shptr_array[i] = shptr_array[i-1];
                shptr_array[i-1] = temp_shptr;
                count ++;
                //std::cout << "number of swaps: " << count << std::endl;
            }

        }
        if(count == 0) break;
        count = 0;
    }
    std::cout << "after sorting" << std::endl;
    
    for(std::size_t i {0}; i<range; ++i)
    {
        shptr_array[i]->print();
    }

    //std::cout << "size of array: " << class_array.size() << std::endl;
    std::cout << "number of iterations: " << iter_count << std::endl;
    std::cout << "ending correctly" << std::endl;
    return 0;
}