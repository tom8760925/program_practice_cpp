#include <iostream>

constinit int n = 2;
constinit static int nn = 3;
int func()
{
    return n * nn;
}
int main()
{
    std::cout << func() << std::endl;
    return 0;
}