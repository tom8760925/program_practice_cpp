#include <iostream>
class a
{
public:
    int n = 0;
    a(int n) : n(n) {};
    explicit operator int() const { return n; }
};

int main()
{

    a _a1(5);

    // int n = _a1; 不能用
    int n = static_cast<int>(_a1);

    std::cout << n << std::endl;

    return 0;
}