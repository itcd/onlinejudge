// main.cpp    
#include <iostream>
#include <string>

#include "Thread.h"

class HelloWorld
{
public:
    DWORD print ()
    {
        std::cout << "Hello World!" << std::endl;
        return 0;
    }
};
int main(void)
{
    // Random object with DWORD method (void)
    HelloWorld world;
    // thread should call print method of world.
    Thread<HelloWorld> thread(&world, &HelloWorld::print);
    if (thread.start())
        std::cout << "Thread start()" << std::endl;
    thread.join(); // wait for thread
    return 0;
}
