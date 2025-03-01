class a
{
public:
    virtual int sum(int, int) = 0;
};

class b : public a
{
public:
    int sum(int, int) override;
};
int b::sum(int n1, int n2)
{
    return n1 * n2;
}
int main()
{
    b _b;
    _b.sum(1, 2);
    return 0;
}