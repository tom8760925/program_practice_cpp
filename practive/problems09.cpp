#include <vector>
#include <iostream>

class Solution
{
public:
    int majorityElement(std::vector<int> &nums)
    {
        int r = 0;
        for (auto &au : nums)
        {
            if (std::count(nums.begin(), nums.end(), au) > (int(nums.size()) / 2))
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
    std::vector<int> v = {1, 2, 2, 1, 1, 2, 2};
    std::cout << s.majorityElement(v) << std::endl;
    return 0;
}