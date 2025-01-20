#include <iostream>

class a
{
public:
    a(int n);
    operator int();
    int getn();

private:
    int n = 0;
};
a::a(int n)
{
    this->n = n;
}
a::operator int()
{
    return this->n;
}
int a::getn()
{
    return this->n;
}

int main()
{
    a _a1(3);
    int n = 1;
    n += _a1;
    std::cout << n << std::endl;

    return 0;
}