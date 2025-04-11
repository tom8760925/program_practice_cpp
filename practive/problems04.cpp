#include <string>
#include <iostream>
#include <map>

class Solution
{
private:
    std::map<char, char> m = {{'{', '}'}, {'[', ']'}, {'(', ')'}};

public:
    bool isValid(std::string s)
    {
        int ssize = s.size();
        if (ssize % 2 == 1)
        {
            return false;
        }
        if (m[s[0]] == s[1])
        {
            for (int n = 0; n < ssize; n += 2)
            {
                if (m[s[n]] != s[n + 1])
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            for (int n = 0; n < (ssize / 2); n++)
            {
                if (m[s[n]] != s[(ssize - 1) - n])
                {
                    return false;
                }
            }
            return true;
        }
    }
};
int main()
{
    Solution s;
    std::cout << s.isValid("{([])}") << std::endl;
    return 0;
}