#include <iostream>
#include <functional>

int main()
{
    int n1 = 5;

    int n2 = std::ref(n1);

    std::cout << n1 << std::endl;
    std::cout << n2 << std::endl;

    return 0;
}