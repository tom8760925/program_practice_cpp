#include <iostream>

class a
{
public:
    a(int n);
    int operator+();

private:
    int n = 0;
};
a::a(int n)
{
    this->n = n;
}
int a::operator+()
{
    return this->n;
}

int main()
{
    a _a1(3);

    int n = 1;
    n = n + _a1.operator+();
    std::cout << n << std::endl;

    return 0;
}