#include <iostream>

class MyClass {
public:
    void methodOne() {
        std::cout << "Method One called" << std::endl;
    }

    void methodTwo() {
        std::cout << "Method Two called" << std::endl;
    }

    void methodThree() {
        std::cout << "Method Three called" << std::endl;
    }
};

using MemberFunctionPointer = void (MyClass::*)();

int main() {
    MyClass myObject;
    MemberFunctionPointer methodToCall = &MyClass::methodTwo; // Choose the method dynamically

    // Call the method
    (myObject.*methodToCall)(); // Syntax to call a member function pointer

    return 0;
}
