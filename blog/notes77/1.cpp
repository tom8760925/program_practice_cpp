#include <iostream>
template <typename T>
class base
{
public:
    void Getn()
    {
        static_cast<T *>(this)->Getn1();
    }

private:
    friend T;
};
class a : public base<a>
{
public:
    explicit a(int n) : n(n) {};
    void Getn1() const
    {
        std::cout << n << std::endl;
    }

private:
    int n = 0;
};

int main()
{
    a _a(5);
    _a.Getn();

    return 0;
}