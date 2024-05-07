#include <iostream>
#include <string>
using namespace std;
template <typename T>
void a(T n);
template <typename T>
void a(T n, T b);
template <typename T, typename TT>
void a(T n, TT b);
int main()
{
    int i = 1;
    int ii = 2;
    string s = "A";
    a(i);
    cout << "------\n";
    a(i, ii);
    cout << "------\n";
    a(i, s);
    cout << endl;
    return 0;
}
template <typename T>
void a(T n)
{
    cout << "p:" << n << '\n';
}
template <typename T>
void a(T n, T b)
{
    cout << "p:" << n << "|" << b << '\n';
}
template <typename T, typename TT>
void a(T n, TT b)
{
    cout << "p:" << n << "|" << b << '\n';
}