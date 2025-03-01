#include <iostream>
#include <future>
#include <chrono>

using namespace std::chrono_literals;

int func(int n)
{
    for (int i = 0; i < 50; i++)
    {
        n += i;
    }
    return n;
}

void funcf1()
{
    auto asy = std::async(std::launch::async, func, 1);
    // 取得值
    std::cout << asy.get() << std::endl;
}
void funcf2()
{
    auto asy = std::async(std::launch::async, func, 1);
    // 等待
    asy.wait();
    // 取得值
    std::cout << asy.get() << std::endl;
}
void funcf3()
{
    auto asy = std::async(std::launch::async, func, 1);
    // 狀態
    std::cout << asy.valid() << std::endl;
    // 取得值
    std::cout << asy.get() << std::endl;
}
void funcf4()
{
    auto asy = std::async(std::launch::async, func, 1);
    // 等待結果時間超過或返回結果。
    std::future_status s = asy.wait_for(1s);
    switch (s)
    {
        // 延期
    case std::future_status::deferred:
        std::cout << "deferred" << std::endl;
        break;
        // 就緒
    case std::future_status::ready:
        std::cout << "ready" << std::endl;
        break;
        // 超時
    case std::future_status::timeout:
        std::cout << "timeout" << std::endl;
        break;
    }
    // 取得值
    std::cout << asy.get() << std::endl;
}
void funcf5()
{
    auto asy = std::async(std::launch::async, func, 1);
    // 等待結果會暫停直到超時或就緒。
    std::future_status s = asy.wait_until(std::chrono::system_clock::time_point(1s));
    switch (s)
    {
        // 延期
    case std::future_status::deferred:
        std::cout << "deferred" << std::endl;
        break;
        // 就緒
    case std::future_status::ready:
        std::cout << "ready" << std::endl;
        break;
        // 超時
    case std::future_status::timeout:
        std::cout << "timeout" << std::endl;
        break;
    }
    // 取得值
    std::cout << asy.get() << std::endl;
}

int main()
{
    std::cout << "====1===" << std::endl;
    funcf1();
    std::cout << "====2===" << std::endl;
    funcf2();
    std::cout << "====3===" << std::endl;
    funcf3();
    std::cout << "====4===" << std::endl;
    funcf4();
    std::cout << "====5===" << std::endl;
    funcf5();
    return 0;
}