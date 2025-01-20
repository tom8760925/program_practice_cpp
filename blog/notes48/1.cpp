#include <iostream>

int main()
{
    int *n = new int(1);
    std::cout << *n << std::endl;
    delete n;

    int *nn = new int[5];
    nn[0] = 1;
    std::cout << nn[0] << std::endl;
    delete[] nn;

    return 0;
}