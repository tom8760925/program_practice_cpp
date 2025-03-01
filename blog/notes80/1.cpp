#include <iostream>
int main()
{
    std::cout << "=====1====" << std::endl;
    int a1 = 0, a2 = 5;
    // b為int
    decltype(a1) b = 0;
    // c為int
    decltype(a1 + a2) c = 0;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << "=====2====" << std::endl;
    // d為int&
    decltype((a1)) d = a1;
    std::cout << d << std::endl;
    std::cout << "=====3====" << std::endl;
    int *a3 = &a1;
    // e為int*
    decltype(a3) e = &a1;
    std::cout << *e << std::endl;

    return 0;
}