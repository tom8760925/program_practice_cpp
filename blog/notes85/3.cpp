#include <iostream>
#include <future>
#include <thread>

int func(int n1, int n2)
{

    return n1 + n2;
}

void funcp1()
{
    std::packaged_task<int(int, int)> task(func);

    std::future<int> f = task.get_future();

    task(5, 5);
    //  沒有使用get也會執行
    std::cout << f.get() << std::endl;
}
void funcp2()
{
    std::packaged_task<int(int, int)> task(func);

    std::future<int> f = task.get_future();
    // 啟動線程
    std::thread t(std::ref(task), 5, 5);
    std::cout << f.get() << std::endl;
    // 等待
    t.join();
}
void funcp3()
{
    std::packaged_task<int(int, int)> task(func);

    std::future<int> f = task.get_future();
    // 啟動線程
    std::thread t(std::ref(task), 5, 5);
    std::cout << f.get() << std::endl;
    // 等待
    t.join();

    // 重製
    task.reset();
    // 重新取得
    f = task.get_future();
    // 啟動線程
    t = std::thread(std::ref(task), 10, 10);
    std::cout << f.get() << std::endl;
    // 等待
    t.join();
}

int main()
{
    std::cout << "====1===" << std::endl;
    funcp1();
    std::cout << "====2===" << std::endl;
    funcp2();
    std::cout << "====3===" << std::endl;
    funcp3();
    return 0;
}