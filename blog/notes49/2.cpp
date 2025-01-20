#include <iostream>

class a
{
public:
    // 朋友類別
    friend class b;
    // 朋友函式
    friend int getn(a &_a);

private:
    int n = 0;
};
// 使用a的n
int getn(a &_a)
{
    return _a.n;
}

class b
{
public:
    // 設定a的n
    void setn(a &_a, int n);
    // 使用a的n
    int getn(a &_a) const;
};
// 設定a的n
void b::setn(a &_a, int n)
{
    _a.n = n;
}
// 使用a的n
int b::getn(a &_a) const
{
    return _a.n;
}

int main()
{
    a _a;
    b _b;
    _b.setn(_a, 2);
    std::cout << _b.getn(_a) << std::endl;
    std::cout << getn(_a) << std::endl;
    return 0;
}