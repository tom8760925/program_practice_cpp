#include <string>
#include <iostream>
#include <algorithm>

class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        std::string ans = "";
        if (strs.size() <= 200)
        {
            std::sort(strs.begin(), strs.end());
            std::string first = strs[0], last = strs[strs.size() - 1];
            for (int n = 0; n < int(std::min(first.size(), last.size())); n++)
            {
                if (first[n] != last[n])
                {
                    return ans;
                }
                ans += first[n];
            }
        }
        else
        {
            return ans;
        }
        return ans;
    }
};
int main()
{
    std::vector<std::string> v = {"flower", "flow", "flight"};
    Solution s;
    std::cout << s.longestCommonPrefix(v) << std::endl;

    return 0;
}