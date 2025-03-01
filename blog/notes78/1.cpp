#include <iostream>
#include <functional>

void func(int n)
{
    std::cout << n << std::endl;
}

int main()
{
    std::cout << "====1===" << std::endl;
    std::function<void(int)> _func1 = func;
    _func1(5);
    std::cout << "====2===" << std::endl;
    std::function<void(int)> _func2 = [](int n)
    { std::cout << n << std::endl; };
    _func2(10);

    return 0;
}