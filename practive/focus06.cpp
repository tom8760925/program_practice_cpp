#include <iostream>

// 跟編譯器有關的
inline int func(int i)
{
    return i + 1;
}

int main()
{
    // 易變的 跟編譯器有關的
    volatile int i = 1;
    int a = i;

    // 在編譯器可能會變成a=1，但如果用volatile，就會強制變成a=i;
    std::cout << "a:" << a << '\n';
    std::cout << "--------\n";
    // 在編譯器會調用函數，但如果用inline，會可能變成i + 1
    std::cout << "func:" << func(i) << '\n';

    std::cout << std::endl;

    return 0;
}