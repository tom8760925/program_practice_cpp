#include <iostream>
#include <time.h>

int main()
{
    // 回傳00:00到現在的秒數
    std::cout << std::time(NULL) << std::endl;
    return 0;
}