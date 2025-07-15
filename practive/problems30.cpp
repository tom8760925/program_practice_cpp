#include <iostream>
#include <vector>
#include <string>

class Solution
{
private:
    // 執行回朔法
    void partitonarr(std::vector<std::vector<std::string>> &strarrs, std::vector<std::string> &strarr, std::string s, int i)
    {
        // 取得大小
        int len = s.size();
        // 判斷是否已經到底了
        if (i == len)
        {
            strarrs.push_back(strarr);
            return;
        }
        // 迴圈n=i的原因是，要依序尋找是否符合
        // n=0 strarr新增a
        // n=1 strarr新增a
        // n=2 strarr新增b
        // 接著回去n=2和i=1時 ab會去判斷
        // 跑完迴圈
        for (int n = i; n < int(s.size()); n++)
        {

            // 判斷是否符合
            if (ispartition(s, i, n))
            {
                // 找出所有可能
                strarr.push_back(s.substr(i, n - i + 1));
                partitonarr(strarrs, strarr, s, n + 1);
                strarr.pop_back();
            }
        }
    }
    // 判斷
    bool ispartition(std::string s, int l, int r)
    {
        while (l < r)
        {
            if (s[l++] != s[r--])
            {
                return false;
            }
        }
        return true;
    }

public:
    std::vector<std::vector<std::string>> partition(std::string s)
    {
        std::vector<std::vector<std::string>> strarrs = {};
        std::vector<std::string> strarr = {};
        partitonarr(strarrs, strarr, s, 0);
        return strarrs;
    }
};

int main()
{
    Solution s;
    for (auto au : s.partition("aab"))
    {
        std::cout << "[";
        for (auto aut : au)
        {
            std::cout << aut << ",";
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}