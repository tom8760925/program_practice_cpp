#include <iostream>

class a
{
public:
    int n1 = 0, n2 = 0;
    a();
    a(int, int);

    a operator+(a &_a)
    {
        this->n1 += _a.n1;
        this->n2 += _a.n2;
        a ra(this->n1, this->n2);
        return ra;
    }
    int getsun();
};
a::a()
{
}
a::a(int n1, int n2)
{
    this->n1 = n1;
    this->n2 = n2;
}
int a::getsun()
{
    return this->n1 + this->n2;
}
int main()
{
    a a1(2, 3), a2(4, 5), a3;
    a3 = a1 + a2;
    std::cout << a3.getsun() << std::endl;
    return 0;
}