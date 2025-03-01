#include <iostream>
template <typename T>
T func(T a, T b)
{
    return a + b;
}

int main()
{
    std::cout << "=====1====" << std::endl;
    decltype(func(5, 5)) a = 0;

    std::cout << a << std::endl;

    return 0;
}