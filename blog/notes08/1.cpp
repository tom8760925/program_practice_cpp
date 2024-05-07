#include <iostream>
#include <string>
using namespace std;
void a(int n);
void a(string n);
void a(bool n);
int main()
{
    int i = 1;
    string s = "A";
    bool b = true;
    a(i);
    cout << "------\n";
    a(s);
    cout << "------\n";
    a(b);
    cout << endl;
    return 0;
}
void a(int n)
{
    cout << "p:" << n << '\n';
}
void a(string n)
{
    cout << "p:" << n << '\n';
}
void a(bool n)
{
    cout << "p:" << n << '\n';
}