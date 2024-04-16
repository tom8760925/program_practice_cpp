#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<string, int> a = {{"a", 1}, // 宣告
                                    {"b", 2},
                                    {"c", 3},
                                    {"d", 4}};
    cout << "p:" << a["a"] << '\n';
    cout << "--------\n";
    if (a.insert(make_pair("e", 5)).second) // 新增，如果鍵值已經有就會新增失敗回傳false
    {
        cout << "p:true" << '\n';
    }
    cout << "p:" << a["e"] << '\n';
    cout << "--------\n";
    cout << "p:" << a.count("a") << '\n'; // 用鍵值找是否存在
    cout << "p:" << a.count("f") << '\n';
    a.insert({"f", 6});
    cout << "p:" << a.count("f") << '\n';
    cout << "--------\n";
    cout << "p:" << a.size() << '\n'; // 大小
    cout << "--------\n";
    a.erase("e"); // 刪除
    a.clear();
    if (a.empty()) // 判斷是否為空
    {
        cout << "p:0" << '\n';
    }
    cout << endl;
    return 0;
}