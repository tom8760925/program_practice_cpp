#include <iostream>

class a
{
public:
    int getn(int n);
    // 靜態函數
    static int getn2(int n);

private:
    int nn = 1;
    // 靜態變數
    static int n;
};
// 需要宣告靜態變數的起始值
int a::n = 0;
int a::getn(int n)
{
    this->n += n;
    return this->n + this->nn;
}
// 宣告靜態函數
int a::getn2(int _n)
{
    // 不能用this->n
    n += _n;
    // 不能用非靜態外部變數
    // 所以不能用，this->n+this->nn
    return n;
}

int main()
{
    a _a;
    a _a1;
    std::cout << _a.getn(1) << std::endl;
    std::cout << _a1.getn(1) << std::endl;
    std::cout << "===========" << std::endl;
    std::cout << _a.getn2(1) << std::endl;
    std::cout << _a1.getn2(1) << std::endl;
    return 0;
}