#include <iomanip>
#include <iostream>

int main()
{
    // 增加空格
    std::cout << std::setw(4) << "a" << std::endl;
    // 將空格換成其他
    std::cout << std::setfill('=') << std::setw(4) << "a" << std::endl;
    return 0;
}

