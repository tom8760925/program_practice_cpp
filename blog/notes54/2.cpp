// 2.cpp
struct c
{
    int n1;
    int n2;
};

// 1.cpp
class a
{
public:
    int sum(struct c _c);
};
int a::sum(struct c _c)
{
    return _c.n1 + _c.n2;
}

// 2.cpp
class b : public a
{
public:
};

int main()
{
    struct c _c;
    _c.n1 = 1;
    _c.n2 = 2;
    b *_b = new b();
    _b->sum(_c);
    return 0;
}