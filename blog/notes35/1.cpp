#include <iostream>

// 列舉
enum a
{
    aa,
    aaa
};
// 列舉指定int
enum b : int
{
    bb = 1,
    bbb = 2
};
// 使用namespace的enum
namespace c
{
    enum C
    {
        cc,
        ccc
    };
}
// 使用typedef的enum
typedef enum d
{
    dd,
    ddd
} D;
// 使用class的enum
enum class e
{
    ee,
    eee
};
// 列舉指定char
enum f : char
{
    ff = 'a',
    fff = 'b'
};

void funca();
void funcb();
void funcc();
void funcd();
void funce();
void funcf();

int main()
{
    funca();
    funcb();
    funcc();
    funcd();
    funce();
    funcf();
    return 0;
}

void funca()
{
    std::cout << "a--------" << std::endl;
    std::cout << "p:" << aa << std::endl;
    std::cout << "p:" << aaa << std::endl;
    std::cout << "p:" << a::aa << std::endl;
    std::cout << "p:" << a::aaa << std::endl;
}

void funcb()
{
    std::cout << "b--------" << std::endl;
    std::cout << "p:" << bb << std::endl;
    std::cout << "p:" << bbb << std::endl;
    std::cout << "p:" << b::bb << std::endl;
    std::cout << "p:" << b::bbb << std::endl;
}
void funcc()
{
    std::cout << "c--------" << std::endl;
    std::cout << "p:" << c::cc << std::endl;
    std::cout << "p:" << c::ccc << std::endl;
    std::cout << "p:" << c::C::cc << std::endl;
    std::cout << "p:" << c::C::ccc << std::endl;
}
void funcd()
{
    std::cout << "d--------" << std::endl;
    std::cout << "p:" << dd << std::endl;
    std::cout << "p:" << ddd << std::endl;
    std::cout << "p:" << D::dd << std::endl;
    std::cout << "p:" << D::ddd << std::endl;
}
void funce()
{
    std::cout << "e--------" << std::endl;
    std::cout << "p:" << int(e::ee) << std::endl;
    std::cout << "p:" << int(e::eee) << std::endl;
}
void funcf()
{
    std::cout << "f--------" << std::endl;
    std::cout << "p:" << f::ff << std::endl;
    std::cout << "p:" << f::fff << std::endl;
}