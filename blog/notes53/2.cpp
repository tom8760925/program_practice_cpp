#include <iostream>

// a抽象化圓週長
class a
{
public:
    virtual int r() = 0;
};

// b是輸出圓周長和面積
class b : public a
{
public:
    b(int _round) : round(_round) {};
    int r() override;
    int CircleArea();

private:
    int round;
};
int b::r()
{
    return this->round * 2 * 3.14;
}
int b::CircleArea()
{
    return this->round * this->round * 3.14;
}

// c是輸出圓周長和圓柱
class c : public a
{
public:
    c(int _round) : round(_round) {};
    int r() override;
    int Cylinder(int);

private:
    int round;
};
int c::r()
{
    return this->round * 2 * 3.14;
}
int c::Cylinder(int h)
{
    return this->round * this->round * h * 3.14;
}

int main()
{
    b _b(5);
    std::cout << _b.r() << std::endl;
    std::cout << _b.CircleArea() << std::endl;
    c _c(5);
    std::cout << _c.r() << std::endl;
    std::cout << _c.Cylinder(5) << std::endl;
    return 0;
}
