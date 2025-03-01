#include <set>
#include <iostream>
void func(std::set<int> n)
{
    for (auto au : n)
    {
        std::cout << au << std::endl;
    }
}
int main()
{
    std::cout << "====1===" << std::endl;
    // 宣告
    std::set<int> n{1, 2, 3, 4, 5};
    func(n);
    std::cout << "====2===" << std::endl;
    // 新增
    n.insert(5);
    func(n);
    std::cout << "====3===" << std::endl;
    // 刪除
    n.erase(5);
    func(n);
    std::cout << "====3===" << std::endl;
    // 是否存在
    std::cout << n.count(1) << std::endl;
    std::cout << "====4===" << std::endl;
    // 清空
    n.clear();
    func(n);
    std::cout << "====5===" << std::endl;
    // 是否為空
    std::cout << n.empty() << std::endl;

    return 0;
}