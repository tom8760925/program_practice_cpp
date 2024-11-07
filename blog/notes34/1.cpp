#include "1.hpp"

void a::aa()
{
    std::cout << "aa" << std::endl;
}

void a::ab()
{
    _b = new b();
    _b->bb();
}