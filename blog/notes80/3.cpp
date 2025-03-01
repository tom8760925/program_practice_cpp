#include <iostream>
template <typename T>
auto func(T n1, T n2) -> decltype(n1 + n2)
{
    return n1 + n2;
}
int main()
{
    std::cout << func(1, 2) << std::endl;
    return 0;
}