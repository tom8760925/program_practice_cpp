#include <iostream>
#include <math.h>
using namespace std;
class Solution
{
public:
    bool isPalindrome1(int x) // 使用字串判斷
    {
        if (x <= 0) // 小於等於是否為０
        {
            return false;
        }
        string data = to_string(x);       // 轉換字串
        int len = data.length();          // 字串長度
        for (int n = 0; n < len / 2; n++) // 判斷
        {
            if (data[n] != data[len - (n + 1)])
            {
                return false;
            }
        }
        return true;
    }
    bool isPalindrome2(int x) // 使用數值判斷
    {
        if (x <= 0) // 小於等於是否為０
        {
            return false;
        }
        int xx = x;
        int len = 0;
        while (true) // 數值長度
        {
            xx /= 10;
            len++;
            if (xx == 0)
            {
                break;
            }
        }
        xx = x;
        for (int n = 0; n < len / 2; n++) // 判斷
        {
            int a = pow(10, (len - 1) - (2 * n)); // 10的單數次方
            if ((xx / a) != (xx % 10))
            {
                return false;
            }
            xx %= a;
            xx /= 10;
        }
        return true;
    }
};

int main()
{
    Solution s;
    int input_number = 12321;
    bool r = s.isPalindrome1(input_number);
    printf("p:%s\n", r ? "true" : "false"); // 輸出
    return 0;
}