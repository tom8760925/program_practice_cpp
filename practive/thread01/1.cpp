#include "2.hpp"

#include <iostream>

int main()
{

    a *_a = new a();

    while (true)
    {
        int n = 0;
        std::cout << "p:";
        std::cin >> n;
        if (n == 1)
        {
            _a->thread_main();
        }
        else if (n == 2)
        {
            _a->thread_stop();
        }
        else
        {
            break;
        }
    }

    return 0;
}