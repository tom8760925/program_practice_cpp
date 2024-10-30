#include <iostream>

class a
{
public:
    a()
    {
        std::cout << "a\n";
    }
    a(int k, int v)
    {
        this->k = k;
        this->v = v;
        std::cout << "a:" << this->k << "," << this->v << '\n';
    }
    ~a()
    {
        std::cout << "a:" << this->k << "+" << this->v << "=" << this->k + this->v << '\n';
    }

private:
    int k = 0;
    int v = 0;
};
class b : public a
{
public:
    b()
    {
        std::cout << "b\n";
    }
    b(int k, int v)
    {
        this->k = k;
        this->v = v;
        std::cout << "b:" << this->k << "," << this->v << '\n';
    }
    ~b()
    {
        std::cout << "b:" << this->k << "+" << this->v << "=" << this->k + this->v << '\n';
    }

private:
    int k = 0;
    int v = 0;
};
int main()
{
    a *aa1 = new a;
    delete aa1;

    std::cout << "--------\n";
    a *aa2 = new a(1, 2);
    delete aa2;

    std::cout << "--------\n";
    a *aa3 = new b;
    delete aa3;

    std::cout << "--------\n";
    a *aa4 = new b;
    delete aa4;

    std::cout << "--------\n";
    b *bb1 = new b();
    delete bb1;

    std::cout << "--------\n";
    b *bb2 = new b(1, 2);
    delete bb2;

    return 0;
}