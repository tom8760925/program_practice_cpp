#include <iostream> 
using namespace std;
int main(){
    try
    {
        throw "1";//發生例外
    }
    catch(const exception& e)//根據例外顯示結果
    {
        cerr << e.what() << '\n';
    }
    cout<<endl;
    return 0;
}