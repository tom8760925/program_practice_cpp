#include <iostream>

int main()
{
    register int n = 1;
    for (int nn = 1; nn < 100; nn++)
    {
        std::cout << n << std::endl;
        n += nn;
    }
    return 0;
}