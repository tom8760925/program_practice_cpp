#include <stdio.h>

class a
{
public:
    // 虛擬函式
    virtual void func1()
    {
        printf("a\n");
    }
};

class b : public a
{
public:
    // 虛擬函式
    virtual void func1() override
    {
        printf("b\n");
    }
};

int main()
{
    a *aa = new a();
    // 父類別有實作，以父類別為主
    aa->func1();

    a *aaa = new b();
    // 子類別有實作，以子類別為主
    aaa->func1();

    b *bb = new b();
    // 子類別有實作，以子類別為主
    bb->func1();

    return 0;
}