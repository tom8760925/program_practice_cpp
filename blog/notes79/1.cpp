#include <iostream>
#include <tuple>

int main()
{
    // 宣告
    std::tuple<int, std::string, int> t1(100, "aa", 200);
    std::tuple<int, std::string, int> t2 = std::make_tuple(100, "aa", 200);
    std::cout << "===1===" << std::endl;
    // 讀取
    std::cout << std::get<0>(t1) << std::endl;
    std::cout << std::get<1>(t1) << std::endl;
    std::cout << std::get<2>(t1) << std::endl;
    std::cout << "===2===" << std::endl;
    // 讀取
    auto [a, b, c] = t1;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << "===3===" << std::endl;
    // 數量
    std::cout << std::tuple_size<decltype(t1)>::value << std::endl;

    return 0;
}