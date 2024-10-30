#include <iostream>

// 變數
void func1(int x)
{
    static int xx = 0;
    xx += x;
    printf("xx:%d\n", xx);
}

// static member variable
class a
{
public:
    static void setax(int x)
    {
        ax += x;
    }
    static int getax()
    {
        return ax;
    }

private:
    static int ax;
};
int a::ax = 0;

// class
class b
{
public:
    void setbx(int x)
    {
        bx += x;
    }
    int getbx()
    {
        return bx;
    }

private:
    int bx = 0;
};

void func2(int x)
{
    static b bb;
    bb.setbx(x);
    printf("bx:%d\n", bb.getbx());
}

int main()
{
    printf("變數\n");
    func1(1);
    func1(1);
    func1(1);

    printf("----------\n");
    printf("static member variable\n");
    a::setax(1);
    printf("pa:%d\n", a::getax());
    a::setax(1);
    printf("pa:%d\n", a::getax());
    a::setax(1);
    printf("pa:%d\n", a::getax());

    printf("---------\n");
    printf("class\n");
    func2(1);
    func2(1);
    func2(1);

    return 0;
}