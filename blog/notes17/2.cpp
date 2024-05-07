#include <iostream>
#include <mutex>
#include <thread>

std::mutex mmutex;
int n = 0;

void a(char b)
{
    std::lock_guard<std::mutex> lock(mmutex); // 自動上鎖，程序結束後自動解鎖
    for (int i = 0; i <= 5; i++)
    {
        printf("p:%d(%c)\n", i, b);
        ++n;
    }
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