#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>

class Solution
{
private:
    void generate(int l, int r, std::string s, int n, std::vector<std::string> &v)
    {
        // 判斷數量左右數量是否一樣
        if (l == n && l == r)
        {
            v.push_back(s);
        }
        // 左邊小於n就左邊+1
        if (l < n)
        {
            generate(l + 1, r, s + "(", n, v);
        }
        // 右邊小於左邊就右邊+1
        if (r < l)
        {
            generate(l, r + 1, s + ")", n, v);
        }
    }

public:
    std::vector<std::string> generateParenthesis(int n)
    {
        std::vector<std::string> v = {};
        std::string s = "";
        generate(0, 0, "", n, v);
        return v;
    }
};
int main()
{
    Solution s;
    for (auto &au : s.generateParenthesis(3))
    {
        std::cout << au << std::endl;
    }
    return 0;
}