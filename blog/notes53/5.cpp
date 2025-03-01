class a
{
public:
    int add(int, int);
    double add(double, double);
};
int a::add(int n1, int n2)
{
    return n1 + n2;
}
double a::add(double d1, double d2)
{
    return d1 + d2;
}

int main()
{
    a _a;
    return 0;
}