#include <iostream>
#include <string>
using namespace std;
struct t
{
    int a;
    string b;
};
void aa(const t &tt);
void bb(t &tt);
int main()
{
    t a = {1, "A"};
    int b = 2;
    int &c = b;
    aa(a);
    cout << "------\n";
    bb(a);
    cout << "------\n";
    cout << "p:" << a.a << '\n';
    cout << "p:" << a.b << '\n';
    cout << "------\n";
    c = 3;
    cout << "p:" << b << '\n';
    cout << endl;
    return 0;
}
void aa(const t &tt)
{
    cout << "p:" << tt.a << '\n';
    cout << "p:" << tt.b << '\n';
}
void bb(t &tt)
{
    tt.a = 2;
    tt.b = "B";
    cout << "p:" << tt.a << '\n';
    cout << "p:" << tt.b << '\n';
}