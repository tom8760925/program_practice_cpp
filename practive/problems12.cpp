#include <string>
#include <iostream>
#include <vector>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int r = 0;
        std::vector<char> v = {};
        for (auto &au : s)
        {
            if (std::count(v.begin(), v.end(), au) == 0)
            {
                v.push_back(au);
                if (int(v.size()) > r)
                {
                    r = v.size();
                }
            }
            else
            {
                v.clear();
            }
        }
        return r;
    }
};
int main()
{
    Solution s;
    std::cout << s.lengthOfLongestSubstring("abcabcbb") << std::endl;
    return 0;
}