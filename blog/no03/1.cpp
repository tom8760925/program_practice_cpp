#include <iostream> 
using namespace std;
int main(){
    int a=11,b=22;
    cout << "p：" << a << endl;
    cout << "p：" << a << '\n';
    cout << "p：" << a;
    cout << endl;
    cout << '\n';
    cout << "p：" << a << "and" << b << endl;
    cout << '\n'<<std::flush;
    return 0;
}