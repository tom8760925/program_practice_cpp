#include <memory>
#include <iostream>
class a
{
public:
    a(int n);
    void ra(std::unique_ptr<int> n);
};
a::a(int n)
{
    std::cout << n << std::endl;
}
void a::ra(std::unique_ptr<int> n)
{
    std::cout << *n << std::endl;
}
int main()
{
    int ii = 5;
    int iii = 6;
    std::cout << "=====1======" << std::endl;
    std::unique_ptr<int> i1 = std::make_unique<int>(ii);
    std::cout << *i1 << std::endl;
    *i1 = 4;
    std::cout << *i1 << std::endl;
    // 轉移
    // i1 = std::make_unique<int>(iii);
    i1 = std::move(std::make_unique<int>(iii));
    std::cout << *i1 << std::endl;
    std::cout << "=====2======" << std::endl;
    std::unique_ptr<const int> i2 = std::make_unique<const int>(ii);
    // std::unique_ptr<int const> i2 = std::make_unique<int const>(ii);一樣
    std::cout << *i2 << std::endl;
    //*i2 = 4; 不能修改值
    i2 = std::move(std::make_unique<int>(iii));
    std::cout << *i2 << std::endl;
    std::cout << "=====3======" << std::endl;
    const std::unique_ptr<int> i3 = std::make_unique<int>(ii);
    std::cout << *i3 << std::endl;
    *i3 = 4;
    // i3 = std::move(std::make_unique<int>(iii)); 不能使用
    std::cout << *i3 << std::endl;
    std::cout << "=====4======" << std::endl;
    std::unique_ptr<a> aa = std::make_unique<a>(1);
    aa->ra(std::move(i1));
    // 釋放
    aa.release();

    return 0;
}