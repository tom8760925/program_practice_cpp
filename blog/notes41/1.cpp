#include <iomanip>
#include <iostream>

int main()
{
    double n = 3.141592;
    double n1 = 3.522;
    // 四捨五入
    std::cout << std::setprecision(2) << n << std::endl;
    // 四捨五入
    std::cout << std::setprecision(1) << n1 << std::endl;
    return 0;
}