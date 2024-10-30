#include <iostream>

// call-by-value
int func1(int a, int b)
{
    a++;
    b++;
    return a + b;
}
// call-by-reference 指標
int func2(int *a, int *b)
{
    *a = *a + 1;
    *b = *b + 1;
    return *a + *b;
}
// call-by-reference 參考
int func3(int &a, int &b)
{
    a = a + 1;
    b = b + 1;
    return a + b;
}

int main()
{
    int a = 1;
    int b = 1;

    std::cout << "a、b:" << a << "、" << b << '\n';
    std::cout << "func1:" << func1(a, b) << '\n';
    std::cout << "a、b:" << a << "、" << b << '\n';

    std::cout << "-------\n";

    std::cout << "a、b:" << a << "、" << b << '\n';
    std::cout << "func2:" << func2(&a, &b) << '\n';
    std::cout << "a、b:" << a << "、" << b << '\n';

    std::cout << "-------\n";

    std::cout << "a、b:" << a << "、" << b << '\n';
    std::cout << "func3:" << func3(a, b) << '\n';
    std::cout << "a、b:" << a << "、" << b << '\n';

    return 0;
}