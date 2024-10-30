#include <iostream>

int main()
{
    int i = 1;

    // 後做
    std::cout << "後做\n";
    // 會先執行cout<<i，後在執行i+1
    std::cout << "i:" << i++ << '\n';
    std::cout << "i:" << i << '\n';

    std::cout << "-------\n";

    // 前做
    std::cout << "前做\n";
    // 會先執行i+1，後執行cout<<i
    std::cout << "i:" << ++i << '\n';
    std::cout << "i:" << i << '\n';

    std::cout << std::endl;

    return 0;
}