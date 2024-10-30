#include <iostream>
using namespace std;
int main()
{
    const int a = 1;
    int const b = 2;
    int aa = 1;
    int bb = 2;
    const int *c = &aa;
    cout << "p:" << a << '\n'; // 不能用a=2，改變值。
    cout << "------\n";
    cout << "p:" << b << '\n'; // 不能用b=3，改變值。
    cout << "------\n";
    cout << "p:" << *c << '\n'; // 不能用*c = 2，改變aa值。
    c = &bb;
    cout << "p:" << *c << '\n'; // 但能改變指數，改為bb。
    cout << "------\n";
    int *const d = &aa;
    cout << "p:" << *d << '\n'; // 不能用d = &bb，改變aa值。
    *d = 2;
    cout << "p:" << *d << '\n'; // 但能改變指數，改為bb。
    cout << "------\n";
    const int *const e = &aa;
    cout << "p:" << *e << '\n'; // 不能用*e = 2 也不能用e = &b;，改變任何值。
    cout << "------\n";
    cout << endl;
    return 0;
}