#include <iostream> 
using namespace std;
int main(){
    try
    {
        throw "A";//發生例外
    }
    catch(const char * e)//根據例外顯示結果
    {
        cerr << "p:" << e << '\n';
    }
    cout<<endl;
    return 0;
}