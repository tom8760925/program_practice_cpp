#include <iostream>
#include <functional>

int main()
{
    int n1 = 5;

    std::reference_wrapper<int> rw1 = n1;
    std::reference_wrapper<int> rw2 = std::ref(n1);
    std::reference_wrapper<int> rw3 = rw2;

    std::cout << rw1.get() << std::endl;
    std::cout << rw2.get() << std::endl;
    std::cout << rw3.get() << std::endl;

    n1 = 1;

    std::cout << "=========" << std::endl;
    std::cout << rw1.get() << std::endl;
    std::cout << rw2.get() << std::endl;
    std::cout << rw3.get() << std::endl;

    return 0;
}