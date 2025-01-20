#include <iomanip>
#include <iostream>

int main()
{
    double n = 3.14;
    // 根據setprecision顯示位數，少的補0
    std::cout << std::setiosflags(std::ios::fixed | std::ios::showpoint) << std::setprecision(3) << n << std::endl;

    return 0;
}