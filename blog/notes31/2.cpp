#include <stdio.h>

class a
{
public:
    // 虛擬函式 一定要實作
    virtual void func1() = 0;
};

class b : public a
{
public:
    // 虛擬函式
    void func1() override
    {
        printf("b\n");
    }
};

int main()
{
    a *aaa = new b();
    // 子類別有實作，以子類別為主
    aaa->func1();

    b *bb = new b();
    // 子類別有實作，以子類別為主
    bb->func1();

    return 0;
}