#include <iostream>
#include <vector>
using namespace std;
template <typename T, typename... TT>
void a(T n, TT... nn);
int main()
{
    int i = 1;
    a(i, 2, 3, 4);
    cout << endl;
    return 0;
}
template <typename T, typename... TT>
void a(T n, TT... nn)
{
    cout << "p:" << n << '\n';
    vector<T> v = {nn...};
    for (auto i : v)
    {
        cout << "p:" << i << '\n';
    }
}