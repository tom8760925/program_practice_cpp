#include <iostream>
#include <future>
#include <thread>

void func(std::future<int> &f)
{
    // 取得值
    int n = f.get();
    std::cout << n << std::endl;
}
void func1(std::promise<int> p)
{
    // 建立關聯
    std::future<int> f = p.get_future();
    // 取得值
    int n = f.get();
    std::cout << n << std::endl;
}

void funcp1()
{
    // 創建
    std::promise<int> p;
    // 設定值
    p.set_value({1});
    // 建立關聯
    std::future<int> f = p.get_future();
    // 確認線程
    std::cout << f.valid() << std::endl;
}
void funcp2()
{
    // 創建
    std::promise<int> p;
    // 建立關聯
    std::future<int> f = p.get_future();
    // 啟動線程
    std::thread t(func, std::ref(f));
    // 設定值
    p.set_value(5);
    // 等待
    t.join();
}
void funcp3()
{
    // 創建
    std::promise<int> p;
    // 設定值
    p.set_value(5);
    // 啟動線程
    std::thread t(func1, std::move(p));
    // 等待
    t.join();
}

int main()
{
    std::cout << "===1===" << std::endl;
    funcp1();
    std::cout << "===2===" << std::endl;
    funcp2();
    std::cout << "===3===" << std::endl;
    funcp3();

    return 0;
}