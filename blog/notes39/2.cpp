#include <iostream>

class a
{
public:
    a(int n);
    operator bool()
    {
        if (n == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

private:
    int n = 0;
};
a::a(int n)
{
    this->n = n;
}

int main()
{
    a _a1(0), _a2(1);

    std::cout << _a1 << std::endl;
    std::cout << _a2 << std::endl;
    return 0;
}