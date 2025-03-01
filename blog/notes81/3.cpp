#include <iostream>

class b
{
};

class a
{
public:
    b *Getb();
};

auto a::Getb() -> b *
{
    return new b();
}

int main()
{
    a _a;
    b *_b = _a.Getb();
    return 0;
}