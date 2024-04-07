#include <iostream>
using namespace std;
int main()
{
    int a = 1;
    auto la = [](int n) -> int
    { return n; };
    cout << "p:" << la(a) << endl;
    return 0;
}