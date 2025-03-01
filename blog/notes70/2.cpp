#include <iostream>
int nn = 1;

//因為用到全域變數
constexpr int func(int n)
{
    return n * nn;
}

int main()
{
    std::cout << func(2) << std::endl;

    return 0;
}