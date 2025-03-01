#include <iostream>
// 資料格式
struct b
{
    int time;
};
class a
{
public:
    // 設定time
    void settime(int n);

private:
    struct b _b;
    // 設定b
    void upb(int n);
};
void a::settime(int n)
{
    this->upb(n);
}
void a::upb(int n)
{
    this->_b.time = n;
}
int main()
{
    a _a;
    _a.settime(5);
    return 0;
}