#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        std::string r = "";
        std::vector<char> v = {};
        for (int n = 0; n < (int(s.size()) - 1); n++)
        {
            for (int nn = n; nn < int(s.size()); nn++)
            {
                if (s[n] == s[nn] && (nn - n) > (int(r.size()) - 1))
                {
                    r.clear();
                    for (int nnn = n; nnn <= nn; nnn++)
                    {
                        r.push_back(s[nnn]);
                    }
                }
            }
        }
        return r;
    }
};
int main()
{
    Solution s;
    std::cout << s.longestPalindrome("babcad") << std::endl;
    return 0;
}