#include <vector>
#include <iostream>

class Solution
{
public:
    int singleNumber(std::vector<int> &nums)
    {
        int r = 0;
        for (auto &au : nums)
        {
            if (std::count(nums.begin(), nums.end(), au) == 1)
            {
                r = au;
                return r;
            }
        }
        return r;
    }
};
int main()
{
    Solution s;
    std::vector<int> v = {4, 1, 2, 1, 2};
    std::cout << s.singleNumber(v) << std::endl;
    return 0;
}