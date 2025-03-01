#include <memory>
#include <iostream>
class a
{
public:
    a(int n);
    void ra(std::shared_ptr<int> n);
};
a::a(int n)
{
    std::cout << n << std::endl;
}
void a::ra(std::shared_ptr<int> n)
{
    std::cout << *n << std::endl;
}
int main()
{
    int ii = 5;
    int iii = 6;
    std::cout << "=====1======" << std::endl;
    std::shared_ptr<int> i1 = std::make_shared<int>(ii);
    std::cout << *i1 << std::endl;
    *i1 = 4;
    std::cout << *i1 << std::endl;
    i1 = std::make_shared<int>(iii);
    std::cout << *i1 << std::endl;
    std::shared_ptr<int> i2 = i1;
    std::cout << *i2 << std::endl;
    *i2 = 5;
    std::cout << *i2 << std::endl;
    std::cout << *i1 << std::endl;
    std::cout << "======2=====" << std::endl;
    std::shared_ptr<const int> i3 = std::make_shared<const int>(ii);
    std::cout << *i3 << std::endl;
    //*i3 = 4; 不能用
    std::shared_ptr<const int> i4 = i3;
    std::cout << *i4 << std::endl;
    std::cout << *i3 << std::endl;
    std::cout << "======3=====" << std::endl;
    const std::shared_ptr<int> i5 = std::make_shared<int>(ii);
    std::cout << *i5 << std::endl;
    *i5 = 4;
    std::cout << *i5 << std::endl;
    // i5 = std::make_shared<int>(iii);不能用
    const std::shared_ptr<int> i6 = i5;
    std::cout << *i6 << std::endl;
    std::cout << "======4=====" << std::endl;
    std::shared_ptr<a> _a = std::make_shared<a>(5);
    _a->ra(i1);
    _a.reset();

    return 0;
}