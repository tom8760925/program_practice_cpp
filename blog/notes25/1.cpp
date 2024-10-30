#include <iostream>
using namespace std;
class a
{
public:
    // 建構函數
    a()
    {
        cout << "a\n";
    }
};
class b : public a
{
public:
    // 建構函數
    b()
    {
        cout << "b\n";
    }
};
int main()
{
    // 建立函數
    a *aa = new a;
    cout << "--------\n";
    a *aaa = new b;
    cout << "--------\n";
    // 不能是b *bb = new a;
    b *bb = new b;
    cout << endl;
    return 0;
}