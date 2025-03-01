#include <iostream>
#include <tuple>
#include <map>

struct s
{
    int a = 0;
    std::string s = "";
};

std::tuple<int, std::string, int> func()
{
    return std::make_tuple(1, "b", 2);
}

int main()
{
    std::cout << "======1=====" << std::endl;
    auto [n1, c, n2] = func();
    std::cout << n1 << std::endl;
    std::cout << c << std::endl;
    std::cout << n2 << std::endl;
    std::cout << "=====2=====" << std::endl;
    std::map<int, std::string> m = {{1, "a"}, {2, "b"}};
    for (auto &au : m)
    {
        std::cout << au.first << std::endl;
        std::cout << au.second << std::endl;
    }
    std::cout << "=====3=====" << std::endl;
    s _s(1, "a");
    auto &[s1, s2] = _s;
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;

    return 0;
}