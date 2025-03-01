#include <iostream>

class a
{
public:
    a(int);
};

a::a(int n)
{
    std::cout << n << std::endl;
}
int main()
{
    a _a(1);
    return 0;
}
