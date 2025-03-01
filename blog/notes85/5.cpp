#include <iostream>
#include <future>

int func(int n)
{
    for (int i = 0; i < 50; i++)
    {
        n += i;
    }
    return n;
}

int main()
{
    auto asy = std::async(std::launch::async, func, 1);
    // 轉換成shared_future
    std::shared_future<int> sf = asy.share();
    // 取得值
    std::cout << sf.get() << std::endl;
    std::cout << sf.get() << std::endl;

    return 0;
}