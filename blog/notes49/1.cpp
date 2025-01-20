#include <iostream>

class a
{
public:
    void setn(int n);
    int getn() const;

private:
    int n = 0;
};
void a::setn(int n)
{
    this->n = n;
}
int a::getn() const
{
    // 不能使用
    //  this->n = 1;
    int nn = 1;
    return this->n + nn;
}

int main()
{
    a _a;
    _a.setn(2);
    std::cout << _a.getn() << std::endl;
    return 0;
}