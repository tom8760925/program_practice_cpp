#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct t
{
    void operator()(const int &t)
    {
        cout << "p;" << t << '\n';
    }
    void operator()(const string &t)
    {
        cout << "p;" << t << '\n';
    }
};
struct tt
{
    string a = "";
    void operator()(const int &t)
    {
        a = "int";
    }
    void operator()(const string &t)
    {
        a = "string";
    }
};
int main()
{
    struct t tt;
    struct tt tt2;
    variant<int, string> a, b; // 宣告型態的種類和變數
    a = 11;
    b = "AA";
    visit([](auto &&arg)
          { cout << "p:" << arg << endl; }, a);
    visit(tt, a);
    visit(tt2, a);
    cout << "p;" << tt2.a << '\n';
    cout << endl;
    return 0;
}