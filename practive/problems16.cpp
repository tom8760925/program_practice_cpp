#include <iostream>
#include <vector>
#include <string>
#include <map>

class Solution
{
private:
    std::map<char, std::vector<char>> m = {
        {'0', {' '}},
        {'1', {' ', ' '}},
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}};
    void letter(std::string digits, std::vector<std::string> &r, std::string s)
    {
        for (auto &au : m[digits[0]])
        {
            if (digits.size() != 1)
            {
                letter(digits.substr(1, digits.size()), r, s + au);
            }
            else
            {
                r.push_back(s + au);
            }
        }
    }

public:
    std::vector<std::string> letterCombinations(std::string digits)
    {
        std::vector<std::string> r = {};
        letter(digits, r, "");
        return r;
    }
};
int main()
{
    Solution s;
    for (auto &au : s.letterCombinations("234"))
    {
        std::cout << au << std::endl;
    }
    return 0;
}