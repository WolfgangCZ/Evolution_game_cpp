#include<iostream>

int main ()
{
bool hovno {false};
int zkouska {-1};
hovno = 1;
std::cout << "if 1 : " << hovno << std::endl;
hovno = zkouska;
std::cout << "if -1 : " << hovno << std::endl;
hovno = 0;
std::cout << "if 0 : " << hovno << std::endl;

    return 0;
}