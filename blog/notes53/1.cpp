#include <iostream>

// c假裝是其他檔案的class
class c
{
public:
    c();
};
c::c()
{
    std::cout << "c" << std::endl;
}

// b假裝是其他檔案的class
class b
{
public:
    b();
};
b::b()
{
    std::cout << "b" << std::endl;
}

// b和c假裝是其他函式庫
class a
{
public:
    void getb();
    void getc();
};
// 使用b的函式
void a::getb()
{
    b _b;
}
// 使用b的函式
void a::getc()
{
    c _c;
}

int main()
{
    a _a;
    _a.getb();
    _a.getc();
    return 0;
}
