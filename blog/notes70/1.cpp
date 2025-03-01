#include <iostream>

constexpr int func(int n)
{
    return n * n;
}

int main()
{
    std::cout << func(2) << std::endl;

    return 0;
}