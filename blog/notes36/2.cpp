#include <fstream>
#include <iostream>

using namespace std;

void funci();
void funco();

int main()
{
    funco();
    cout << "=========" << endl;
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
    // 檢查是否開啟正常
    if (_ifstream.fail())
    {
        cout << "err" << endl;
    }
    // 檢查是否開啟
    if (_ifstream.is_open())
    {
        cout << "open" << endl;
    }
    cout << "------" << endl;
    // 沒有錯誤
    cout << "good:" << _ifstream.good() << endl;
    // 資料到結尾時
    cout << "eof:" << _ifstream.eof() << endl;
    // 邏輯錯誤時
    cout << "fail:" << _ifstream.fail() << endl;
    // 讀寫錯誤時
    cout << "bad:" << _ifstream.bad() << endl;
    while (!_ifstream.eof())
    {
        cout << "------" << endl;
        // 將資料輸入到string
        _ifstream >> str;
        // 顯示
        cout << str << endl;
        // 沒有錯誤
        cout << "good:" << _ifstream.good() << endl;
        // 資料到結尾時
        cout << "eof:" << _ifstream.eof() << endl;
        // 邏輯錯誤時
        cout << "fail:" << _ifstream.fail() << endl;
        // 讀寫錯誤時
        cout << "bad:" << _ifstream.bad() << endl;
    }
    cout << "------" << endl;
    // 沒有錯誤
    cout << "good:" << _ifstream.good() << endl;
    // 資料到結尾時
    cout << "eof:" << _ifstream.eof() << endl;
    // 邏輯錯誤時
    cout << "fail:" << _ifstream.fail() << endl;
    // 讀寫錯誤時
    cout << "bad:" << _ifstream.bad() << endl;

    // 關閉讀取
    _ifstream.close();
}

void funco()
{
    // 輸出宣告
    ofstream _ofstream;
    // 開啟檔案或新增檔案
    _ofstream.open("test.txt");

    // 檢查是否開啟正常
    if (_ofstream.fail())
    {
        cout << "err" << endl;
    }
    // 檢查是否開啟
    if (_ofstream.is_open())
    {
        cout << "open" << endl;
    }
    cout << "------" << endl;
    // 沒有錯誤
    cout << "good:" << _ofstream.good() << endl;
    // 資料到結尾時
    cout << "eof:" << _ofstream.eof() << endl;
    // 邏輯錯誤時
    cout << "fail:" << _ofstream.fail() << endl;
    // 讀寫錯誤時
    cout << "bad:" << _ofstream.bad() << endl;

    // 將資料輸出
    _ofstream << "abc\n";
    _ofstream << "def";

    cout << "------" << endl;
    // 沒有錯誤
    cout << "good:" << _ofstream.good() << endl;
    // 資料到結尾時
    cout << "eof:" << _ofstream.eof() << endl;
    // 邏輯錯誤時
    cout << "fail:" << _ofstream.fail() << endl;
    // 讀寫錯誤時
    cout << "bad:" << _ofstream.bad() << endl;
    // 關閉輸出
    _ofstream.close();
}
