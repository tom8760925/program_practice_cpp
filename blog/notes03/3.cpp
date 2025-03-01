#include <iostream>
class a
{
public:
    virtual void func() const = 0;
};
class b : public a
{
public:
    void func() const override
    {
        // 不能this->n += 1;
        std::cout << "1" << std::endl;
    }
    void func1()
    {
        // 可以
        this->n += 1;
        std::cout << "1" << std::endl;
    }

private:
    int n = 0;
};
int main()
{
    b _b;
    _b.func();
    _b.func1();
    return 0;
}