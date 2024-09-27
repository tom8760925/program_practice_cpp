#include <string>
#include <unordered_map>
#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid1(string s) // 將判斷分成兩個
    {
        unordered_map<char, char> um = {{'(', ')'},
                                        {'[', ']'},
                                        {'{', '}'}}; // 建立字典
        int len = s.length();                        // 字串長度
        if (um[s[0]] == s[1])                        // 判斷是否為第一種
        {
            for (int n = 0; n < len; n++) // 迴圈
            {
                if (um[s[n]] == s[n + 1]) // 判斷是否相同
                {
                    n++;
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            for (int n = 0; n < len / 2; n++) // 執行一半迴圈
            {
                if (um[s[n]] != s[(len - 1) - n]) // 判斷是否相同
                {
                    return false;
                }
            }
        }

        return true;
    }
    bool isValid2(string s) // 使用stack簡化判斷
    {
        stack<char> sk; // 宣告
        unordered_map<char, char> um = {{'(', ')'},
                                        {'[', ']'},
                                        {'{', '}'}}; // 建立字典
        for (char c : s)                             // 宣告
        {
            if (um.find(c) != um.end()) // 判斷是否為(、{、[
            {
                sk.push(um[c]); // 將)、]、}加入
            }
            else if (!sk.empty() && sk.top() == c) // 是否stack是否為空和是否為相對
            {
                sk.pop(); // 移除
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution s;
    string n = "([{}])";
    bool r = s.isValid1(n);
    printf("p:%s\n", r ? "true" : "false");
    return 0;
}