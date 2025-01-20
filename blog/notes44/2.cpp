#include <stdlib.h>
#include <time.h>
#include <iostream>

int main()
{
    // 使用種子碼
    std::srand(std::time(NULL));
    std::cout << std::rand() << std::endl;
    return 0;
}