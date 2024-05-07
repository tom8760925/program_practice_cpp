#include <iostream>
#include <thread>
#include <unistd.h>

void a()
{
    printf("p:a\n");
}
void b(int n)
{
    printf("p:%d\n", n);
}
int main()
{
    std::thread t1(a);    // 啟動程序
    std::thread t2(b, 1); // 啟動程序，但編譯器有可能會顯示，但是是沒問題的可以跑的
    printf("---\n");
    std::cout << "p:" << t1.get_id() << std::endl; // ID
    std::cout << "p:" << t2.get_id() << std::endl; // ID
    printf("----\n");
    std::cout << "p:" << t1.joinable() << std::endl; // 程序的狀態
    std::cout << "p:" << t2.joinable() << std::endl; // 程序的狀態
    printf("----\n");
    t1.join();//暫停等待程序完成
    t2.join();
    printf("----\n");
    std::cout << "p:" << t1.joinable() << std::endl; // 程序的狀態
    std::cout << "p:" << t2.joinable() << std::endl; // 程序的狀態
    printf("----\n");
    return 0;
}