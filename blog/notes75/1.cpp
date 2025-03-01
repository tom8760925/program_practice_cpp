#include <iostream>

class a
{
public:
    virtual void Get() = 0;
};
class b : public a
{
public:
    void Get() override
    {
        std::cout << "b" << std::endl;
    }
};
class c : public a
{
public:
    void Get() override
    {
        std::cout << "c" << std::endl;
    }
};

int main()
{
    b _b;
    _b.Get();

    // 成功
    try
    {
        b _b1 = dynamic_cast<b &>(_b);
        _b1.Get();
    }
    catch (std::bad_cast)
    {
        std::cout << "err" << std::endl;
    }

    // 失敗
    try
    {
        c _c = dynamic_cast<c &>(_b);
        _c.Get();
    }
    catch (std::bad_cast)
    {
        std::cout << "err" << std::endl;
    }

    return 0;
}