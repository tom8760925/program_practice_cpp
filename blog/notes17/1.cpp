#include <iostream>
#include <mutex>
#include <thread>

std::mutex mmutex;//宣告
int n = 0;

void a(char b)
{
    mmutex.lock();//鎖上
    for (int i = 0; i <= 5; i++)
    {
        printf("p:%d(%c)\n", i, b);
        ++n;
    }
    mmutex.unlock();//解鎖
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
