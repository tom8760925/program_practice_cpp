#include <iostream>
#include <span>

int main()
{

    int a[] = {1, 2, 3};
    std::span s(a);

    std::cout << s.size() << std::endl;
    return 0;
}