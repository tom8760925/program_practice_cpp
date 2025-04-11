#include <string>
#include <map>
#include <iostream>

class Solution
{
private:
    std::map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

public:
    int romanToInt(std::string s)
    {
        int r = 0;
        for (auto &au : s)
        {
            if (roman[au] != 0)
            {
                r += roman[au];
            }
        }
        return r;
    }
};
int main()
{
    Solution s;
    std::cout << s.romanToInt("III") << std::endl;
    return 0;
}