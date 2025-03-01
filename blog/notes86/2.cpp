#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>

std::condition_variable cv;
std::mutex m;

void func(int id)
{
    int n = 0;
    // 鎖上mutex
    std::unique_lock<std::mutex> lock(m);
    std::cout << "======" << std::endl;
    // 暫停程式並釋放mutex，直到接收到訊息，接收到會再次鎖上mutex
    cv.wait(lock);
    for (int i = 0; i < 50; i++)
    {
        n += i;
    }
    std::cout << "===" << id << "===" << std::endl;
    std::cout << n << std::endl;
}

int main()
{
    // 執行線程
    std::thread t1(func, 1), t2(func, 2), t3(func, 3);
    // 如果沒有暫停，那可能線程還沒建立，就會造成wait沒接收到訊號。
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
    // 傳送訊號
    cv.notify_all();
    // 等待
    t1.join();
    t2.join();
    t3.join();
    return 0;
}