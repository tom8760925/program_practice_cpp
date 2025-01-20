#include <stdlib.h>
#include <iostream>

int main()
{
    // 使用種子碼
    std::srand(1);
    std::cout << std::rand() << std::endl;
    // 使用種子碼
    std::srand(3);
    std::cout << std::rand() << std::endl;
    return 0;
}