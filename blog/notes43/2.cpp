#include <stdlib.h>
#include <iostream>

int func(int down, int up)
{

    return down + std::rand() % (up - down + 1);
}

int main()
{
    // 使用種子碼
    std::srand(1);
    for (int n = 0; n < 10; n++)
    {
        std::cout << n << ":" << func(5, 10) << std::endl;
    }

    return 0;
}