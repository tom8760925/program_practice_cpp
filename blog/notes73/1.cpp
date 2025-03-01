#include <iostream>
class a
{
public:
    int n = 0;
    // 1
    a() noexcept {};
    a(int n) noexcept : n(n) {};
    // 2
    ~a() noexcept {};
    // 3
    a operator+(const a &_a1) noexcept(noexcept(this->n += _a1.n))
    {
        this->n += _a1.n;
        a _a3(this->n);
        return _a3;
    };
};

int main()
{
    a _a1(5), _a2(5), _a3;
    _a3 = _a1 + _a2;
    std::cout << _a3.n << std::endl;
    return 0;
}
