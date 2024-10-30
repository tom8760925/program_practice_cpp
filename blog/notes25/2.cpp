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
    // 解構函數
    ~a()
    {
        cout << "aa\n";
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
    // 解構函數
    ~b()
    {
        cout << "bb\n";
    }
};
int main()
{
    // 建立函數
    a *aa = new a;
    cout << "--------\n";
    delete aa;
    cout << "--------\n";
    a *aaa = new b;
    cout << "--------\n";
    delete aaa;
    cout << "--------\n";
    // 不能是b *bb = new a;
    b *bb = new b;
    cout << "--------\n";
    delete bb;
    cout << endl;
    return 0;
}