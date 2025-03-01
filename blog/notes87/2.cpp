#include <iostream>
#include <thread>

void func1(int &n)
{
    std::cout << n << std::endl;
}
void func2(const int &n)
{
    std::cout << n << std::endl;
}

int main()
{
    int n = 5;
    std::thread t1(func1, std::ref(n)), t2(func2, std::cref(n));
    t1.join();
    t2.join();
    return 0;
}