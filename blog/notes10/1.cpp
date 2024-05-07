#include <iostream>
#include <vector>
using namespace std;
class a
{
public:
    int t = 10;
    void tt()
    {
        cout << "p:" << t << '\n';
    }
};
template <typename T>
class b : public T
{
public:
    void bb()
    {
        T::tt();
    }
};
int main()
{
    b<a> aa;
    aa.tt();
    aa.bb();
    cout << endl;
    return 0;
}