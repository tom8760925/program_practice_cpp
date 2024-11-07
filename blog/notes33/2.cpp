#include "2.hpp"

template <typename T>
void a::test(T t)
{
    std::cout << t << std::endl;
}

template void a::test<int>(int t);
template void a::test<std::string>(std::string t);