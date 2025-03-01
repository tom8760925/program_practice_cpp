#include <iostream>
#include <utility>

int main()
{
    // 宣告
    std::pair<int, std::string> p1(1, "a");
    std::pair<int, std::string> p2 = std::make_pair(1, "a");
    std::cout << "===1===" << std::endl;
    // 使用
    std::cout << p1.first << std::endl;
    std::cout << p1.second << std::endl;

    return 0;
}