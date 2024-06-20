#include <iostream>
#include <vector>
#include <memory>
// #include <iostream>

// class MyClass {
// public:
//     void methodOne() {
//         std::cout << "Method One called" << std::endl;
//     }

//     void methodTwo() {
//         std::cout << "Method Two called" << std::endl;
//     }

//     void methodThree() {
//         std::cout << "Method Three called" << std::endl;
//     }
// };

// using MemberFunctionPointer = void (MyClass::*)();

// int main() {
//     MyClass myObject;
//     MemberFunctionPointer methodToCall = &MyClass::methodTwo; // Choose the method dynamically

//     // Call the method
//     (myObject.*methodToCall)(); // Syntax to call a member function pointer

//     return 0;
// }

class Base
{
    public:
        virtual void print_number() = 0;
};

class Child : public Base
{
    public:
        int number_child = 10;
        Child(int number) : number_child(number) {}
        void print_number()
        {
            std::cout << number_child << std::endl;
        }
};

int main() 
{
    std::vector<std::shared_ptr<Base>> numbers;
    numbers.push_back(std::make_shared<Child>(100));
    numbers.push_back(std::make_shared<Child>(200));
    numbers.push_back(std::make_shared<Child>(300));
    for (auto number : numbers) {
        number->print_number();
    }
    return 0;
}