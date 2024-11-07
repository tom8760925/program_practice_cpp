#include "2.hpp"
#include "1.hpp"

void b::bb()
{
    std::cout << "bb" << std::endl;
}

void b::ba()
{
    _a = new a();
    _a->aa();
}