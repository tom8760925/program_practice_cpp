#include <variant>
struct test
{
    int operator()(int n)
    {
        return n;
    }
    char operator()(char c)
    {
        return c;
    }
};
int main()
{
    std::variant<char, int> a(1);
    std::visit(test(), a);
}
