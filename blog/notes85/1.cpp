#include <iostream>
#include <future>

void func(int n)
{
    for (int i = 0; i < 50; i++)
    {
        n += i;
    }
    std::cout << n << std::endl;
}
int funcr(int n)
{
    for (int i = 0; i < 50; i++)
    {
        n += i;
    }
    return n;
}
void func_async1()
{
    std::cout << "===1===" << std::endl;
    // 在建立時就執行線程
    auto asy = std::async(std::launch::async, func, 1);
    std::cout << "======" << std::endl;
}
void func_async2()
{
    std::cout << "===2===" << std::endl;
    // 等呼叫後才執行線程，使用例如get、wait之類的。
    auto asy = std::async(std::launch::deferred, func, 1);
    std::cout << "======" << std::endl;
}
void func_async3()
{
    std::cout << "===3===" << std::endl;
    // async或deferred
    auto asy = std::async(func, 1);
    std::cout << "======" << std::endl;
}
void func_async4()
{
    std::cout << "===4===" << std::endl;
    // async或deferred
    auto asy = std::async(std::launch::async, funcr, 1);
    std::cout << "======" << std::endl;
    std::cout << asy.get() << std::endl;
}

int main()
{
    func_async1();
    func_async2();
    func_async3();
    func_async4();
    return 0;
}