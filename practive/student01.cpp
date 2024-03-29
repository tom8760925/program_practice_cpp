#include <iostream> //載入指令
#include <string>//載入指令
using namespace std;
void student_input();//函數宣告
int main(){
    student_input();//呼叫函數
    return 0;
}
void student_input(){
    string name="";
    int no=0,score=0;
    cout << "請輸入姓名:";//顯示需要輸入的值
    cin >> name;//輸入的值
    cout << "姓名:" << name << endl;//顯示輸入的值
    cout << "請輸入學號:";//顯示需要輸入的值
    cin >> no;//輸入的值
    cout << "學號:" << no << endl;//顯示輸入的值
    cout << "請輸入成績:";//顯示需要輸入的值
    cin >> score;//輸入的值
    cout << "成績:" << score << endl;//顯示輸入的值
}