#include <iostream>
void func1(const int *n)
{
    int nn = 1;
    // 不能改值*n = 1;
    // 但能改指
    n = &nn;
    std::cout << *n << std::endl;
}
void func2(int *const n)
{
    int nn = 1;
    // 不能改指n = &nn;
    // 但能改值
    *n = nn;
    std::cout << *n << std::endl;
}
int main()
{
    int n = 2;
    func1(&n);
    func2(&n);
}