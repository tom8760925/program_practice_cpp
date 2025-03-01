#include <iostream>
// 資料格式
struct b
{
    int time;
};
// 單純負責b
class c
{
public:
    void upb(int n);
    struct b getb();

private:
    struct b _b;
};
void c::upb(int n)
{
    this->_b.time = n;
}
struct b c::getb()
{
    return this->_b;
}
// 使用c
class a
{

private:
    c _c;
};

int main()
{
    a _a;

    return 0;
}