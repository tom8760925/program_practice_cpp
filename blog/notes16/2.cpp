#include <iostream>
#include <thread>
#include <unistd.h>

void a()
{
    std::thread::id this_id = std::this_thread::get_id(); // 顯示ID
    std::cout << "p:" << this_id << '\n';
    std::cout << std::endl;
}
void b(int n)
{
    while (true)
    {
        printf("p:%d\n", n);
        if (n == 3)
        {
            break;
        }
        std::chrono::milliseconds dura(5000); // 設定時間這邊設定5秒
        std::this_thread::sleep_for(dura);    // 暫停程序執行
        n++;
    }
}
int main()
{
    std::thread t1(a);    // 啟動執行
    std::thread t2(b, 1); // 啟動執行，但編譯器有可能會顯示，但是是沒問題的可以跑的
    printf("---\n");
    t1.join();
    t2.join();
    return 0;
}