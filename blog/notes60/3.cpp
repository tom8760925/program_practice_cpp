#include <memory>
#include <iostream>
int main()
{
    int ii = 5;
    std::cout << "=====1======" << std::endl;
    std::shared_ptr<int> i1 = std::make_shared<int>(ii);
    // 宣告觀察的對象
    std::weak_ptr<int> w1 = i1;
    std::cout << *i1 << std::endl;
    std::cout << "=====2======" << std::endl;
    // 使用者的數量
    std::cout << w1.use_count() << std::endl;
    std::shared_ptr<int> i2 = i1;
    std::cout << w1.use_count() << std::endl;
    std::cout << "=====3======" << std::endl;
    // 是否清空
    std::cout << w1.expired() << std::endl;
    // 清空
    i2.reset();
    i1.reset();
    // 清空後
    std::cout << w1.use_count() << std::endl;
    std::cout << w1.expired() << std::endl;
    return 0;
}