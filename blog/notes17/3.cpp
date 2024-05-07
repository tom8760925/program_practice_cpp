#include <iostream>
#include <mutex>
#include <thread>

std::mutex mmutex;
int n = 0;

void a(char b)
{
    std::unique_lock<std::mutex> lock(mmutex); // 自動上鎖，程序結束後自動解鎖，可以選擇哪裡解鎖，lock_guard沒有這個功能。
    for (int i = 0; i <= 5; i++)
    {
        printf("p:%d(%c)\n", i, b);
        ++n;
    }
    lock.unlock();
}
int main()
{
    std::thread t1(a, 'A');
    std::thread t2(a, 'B');
    t1.join();
    t2.join();
    std::cout << "p：" << n << std::endl;
    return 0;
}