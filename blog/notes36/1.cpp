#include <fstream>
#include <iostream>

using namespace std;

void funci();
void funco();

int main()
{
    funco();
    funci();
    return 0;
}

void funci()
{
    string str = "";
    // 讀取宣告
    ifstream _ifstream;
    // 開啟檔案
    _ifstream.open("test.txt");
    // 將資料輸入到string
    _ifstream >> str;
    // 顯示
    cout << str << endl;
    // 關閉讀取
    _ifstream.close();
}

void funco()
{
    // 輸出宣告
    ofstream _ofstream;
    // 開啟檔案或新增檔案
    _ofstream.open("test.txt");
    // 將資料輸出
    _ofstream << "abc";
    // 關閉輸出
    _ofstream.close();
}