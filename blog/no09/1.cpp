#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    variant<int, string> a, b; // 宣告型態的種類和變數
    a = 11;
    b = "AA";
    cout << "p;" << get<int>(a) << '\n';    // 輸出值
    cout << "p;" << get<string>(b) << '\n'; // 輸出值
    if (get_if<int>(&a) != nullptr)         // 判斷變數的型態是否正確，不正確就輸出nullptr，要記得加上&。
    {
        cout << "p;" << get<int>(a) << '\n';
    }
    cout << endl;
    return 0;
}