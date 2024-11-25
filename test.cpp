#include <iostream>
#include "./src/geometry.h"
#include <chrono>
#include <functional>

void perform_action(int count, std::function<void()> func)
{
    for (int i = 0; i < count; i++)
    {
        func();
    }
}

int ACTION_COUNT = 1*1000*1000;

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    Vector2 vec1 = Vector2{1.0f, 2.0f};
    Vector2 vec2 = Vector2{3.0f, 7.0f};
    perform_action(ACTION_COUNT, [&](){
        Vector2Normalize(vec1);
        });
    auto end1 = std::chrono::high_resolution_clock::now();
    std::cout << "normalize: " << float(std::chrono::duration_cast<std::chrono::microseconds>(end1 - start).count())/1000000 << std::endl;
    perform_action(ACTION_COUNT, [&](){
        Vector2Add(vec1, vec2);
        });
    auto end2 = std::chrono::high_resolution_clock::now();
    std::cout << "add: " << float(std::chrono::duration_cast<std::chrono::microseconds>(end2 - end1).count())/1000000 << std::endl;
    perform_action(ACTION_COUNT, [&](){
        Vector2Distance(vec1, vec2);
        });
    auto end3 = std::chrono::high_resolution_clock::now();
    std::cout << "distance: " << float(std::chrono::duration_cast<std::chrono::microseconds>(end3 - end2).count())/1000000 << std::endl;
    perform_action(ACTION_COUNT, [&](){
        Vector2Scale(vec1, 10.0f);
        });
    auto end4 = std::chrono::high_resolution_clock::now();
    std::cout << "scale: " << float(std::chrono::duration_cast<std::chrono::microseconds>(end4 - end3).count())/1000000 << std::endl;
    perform_action(ACTION_COUNT, [&](){
        Vector2DotProduct(vec1, vec2);
        });
    auto end5 = std::chrono::high_resolution_clock::now();
    std::cout << "dot: " << float(std::chrono::duration_cast<std::chrono::microseconds>(end5 - end4).count())/1000000 << std::endl;
    return 0;
}


