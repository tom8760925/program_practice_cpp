#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix1(vector<string> &strs) // 直接比較
    {
        int len = 0;
        int strs_len = 0;
        char data = ' ';
        bool data_b = true;
        string strs_array = "";
        string r = "";
        len = strs[0].length();
        for (int n = 1; n < int(strs.size()); n++) // 找出字數最低的字串
        {
            strs_array = strs[n];
            strs_len = strs_array.length();
            if (len > strs_len)
            {
                len = strs_len;
            }
        }
        for (int i = 0; i < len; i++) // 比較字串
        {
            data = strs[0][i];
            for (int a = 1; a < int(strs.size()); a++)
            {
                if (data != strs[a][i])
                {
                    data_b = false;
                }
            }
            if (data_b)
            {
                r += data;
                data_b = true;
            }
            else
            {
                data_b = true;
            }
        }
        return r;
    }
    string longestCommonPrefix2(vector<string> &strs) // 先排序後比較
    {
        vector<string> strss = strs;
        int len = 0;
        string strss_end = "";
        string r = "";
        sort(strss.begin(), strss.end()); // 排序
        len = strss[0].length();
        strss_end = strss[strss.size() - 1];
        for (int n = 0; n < len; n++) // 直接比較頭尾字串
        {
            if (strss[0][n] == strss_end[n])
            {
                r += strss[0][n];
            }
            else
            {
                return "";
            }
        }
        return r;
    }
};
int main()
{
    Solution s;
    vector<string> n = {"flower", "flight", "flow"};
    string r = s.longestCommonPrefix2(n);
    cout << "p:" << r << endl;
    return 0;
}