#include <iostream>
#include <math.h>

int main()
{
    // 絕對值
    std::cout << "abs:" << std::abs(-1) << std::endl;
    // 浮點數絕對值
    std::cout << "fabs:" << std::fabs(-1.1) << std::endl;
    // 餘數
    std::cout << "fmod:" << std::fmod(5, 2) << std::endl;
    // 最大值
    std::cout << "fmax:" << std::fmax(5, 2) << std::endl;
    // 最小值
    std::cout << "fmin:" << std::fmin(5, 2) << std::endl;
    // 和平方根
    // √(5*5+2*2)=√(25+4)=√(29)=5.38516
    std::cout << "hypot:" << std::hypot(5, 2) << std::endl;
    // 指數
    std::cout << "exp:" << std::exp(5) << std::endl;
    // 對數
    std::cout << "log:" << std::log(5) << std::endl;
    // 對數10
    std::cout << "log10:" << std::log10(5) << std::endl;
    // 平方
    std::cout << "pow:" << std::pow(5, 2) << std::endl;
    // 平方根
    std::cout << "sqrt:" << std::sqrt(5) << std::endl;
    // sin
    std::cout << "sin:" << std::sin(5) << std::endl;
    // cos
    std::cout << "cos:" << std::cos(5) << std::endl;
    // tan
    std::cout << "tan:" << std::tan(5) << std::endl;
    // 無條件進位
    std::cout << "ceil:" << std::ceil(5.2) << std::endl;
    // 無條件捨棄
    std::cout << "floor:" << std::floor(5.2) << std::endl;
    // 四捨五入
    std::cout << "round:" << std::round(5.2) << std::endl;
    // 去除小數
    std::cout << "trunc:" << std::trunc(5.2) << std::endl;
    // 四捨五入返回int
    std::cout << "rint:" << std::rint(5.2) << std::endl;
    // 檢查有限值
    std::cout << "isfinite:" << std::isfinite(5.2) << std::endl;
    // 檢查為無限值
    std::cout << "isinf:" << std::isinf(5.2) << std::endl;
    // 檢查為NAN
    std::cout << "isnan:" << std::isnan(5.2) << std::endl;
    // 檢查為非零的有限值浮點數
    std::cout << "isnormal:" << std::isnormal(5.2) << std::endl;
    // 檢查為負
    std::cout << "signbit:" << std::signbit(5.2) << std::endl;
    return 0;
}