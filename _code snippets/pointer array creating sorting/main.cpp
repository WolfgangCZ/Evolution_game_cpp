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

std::shared_ptr<Test> find_adress(std::vector<std::shared_ptr<Test>> &tmp, std::shared_ptr<Test> ptr)
{
    for(std::size_t i{0}; i<tmp.size() ;i++)
    {
        if(ptr == tmp[i]);
    }
    return ptr;
}

size_t find_pos_by_adress(std::vector<std::shared_ptr<Test>> &tmp, std::shared_ptr<Test> adress)
{
    for(std::size_t i{0}; i<tmp.size() ;i++)
    {
        if(tmp[i] == adress) return i;
    }
    return 0;

}

int main ()
{
    const std::size_t range {10};
    std::srand(time(0));
    int count {0};
    //std::shared_ptr<Test> ptr_test = std::make_shared<Test>(Test {});
    
    std::vector <std::shared_ptr<Test>> shptr_array{};
    std::vector <std::shared_ptr<Test>> shptr_arr_x{};
    //fill up the array
    for(std::size_t i {0}; i<range; ++i)
    {
        shptr_array.push_back(std::make_shared<Test>(Test{}));
        shptr_arr_x.push_back(std::shared_ptr<Test>{shptr_array[i]});
    }

    std::cout << "before sorting" << std::endl;
    for(std::size_t i {0}; i<range; ++i)
    {
        std::cout << "pos: " << i << ", ";
        shptr_arr_x[i]->print();
    }

    int iter_count {0};
    while(true)
    {
        
        std::shared_ptr<Test> temp_shptr;
        
        for(std::size_t i {1}; i<range; ++i)
        {
            if(shptr_arr_x[i]->get_x() <  shptr_arr_x[i-1]->get_x())
            {
                temp_shptr = shptr_arr_x[i];
                shptr_arr_x[i] = shptr_arr_x[i-1];
                shptr_arr_x[i-1] = temp_shptr;
                count ++;
                //std::cout << "number of swaps: " << count << std::endl;
            }

        }
        if(count == 0) break;
        iter_count++;
        count = 0;
    }
    std::cout << "after sorting" << std::endl;
    
    for(std::size_t i {0}; i<range; ++i)
    {
        std::cout << "pos: " << i << ", ";
        shptr_arr_x[i]->print();
    }

    std::size_t erasing_pos = static_cast<std::size_t>(std::rand()%10);
    //std::cout << "size of array: " << class_array.size() << std::endl;
    std::cout << "number of iterations: " << iter_count << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "size of base ptr array before erase: " << shptr_array.size() << std::endl;
    std::cout << "size of base ptr array x before erase: " << shptr_arr_x.size() << std::endl;
    std::cout << "erasing pos: " << erasing_pos << std::endl;
    std::cout << "returning adress of ptr in base: " << shptr_array[erasing_pos] << std::endl;
    std::cout << "returning adress of ptr in x array: " << find_adress(shptr_array, shptr_array[erasing_pos]) << std::endl;


    shptr_arr_x.erase(shptr_arr_x.begin()+find_pos_by_adress(shptr_array, shptr_array[erasing_pos]));
    shptr_array.erase(shptr_array.begin()+erasing_pos);

    std::cout << "size of base ptr array after erase: " << shptr_array.size() << std::endl;
    std::cout << "size of base ptr array x after erase: " << shptr_arr_x.size() << std::endl;

    std::cout << "printing base pointers" << std::endl;
    for(std::size_t i {0}; i<shptr_array.size(); ++i)
    {
        std::cout << "pos: " << i << ", ";
        shptr_array[i]->print();
    }

    std::cout << "printing x pointers" << std::endl;
    for(std::size_t i {0}; i<shptr_arr_x.size(); ++i)
    {
        std::cout << "pos: " << i << ", ";
        shptr_arr_x[i]->print();
    }

    std::cout << "ending correctly" << std::endl;
    return 0;
}