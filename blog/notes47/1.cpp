#include <iostream>

int func(int n)
{
    // 宣告靜態變數
    static int r = 1;
    r += n;
    return r;
}

int main()
{
    for (int nn = 1; nn < 10; nn++)
    {
        std::cout << func(nn) << std::endl;
    }
    return 0;
}