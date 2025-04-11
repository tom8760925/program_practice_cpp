#include <vector>
#include <iostream>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::vector<int> r = {};
        for (int n = 0; n < int(nums.size()) - 1; n++)
        {
            for (int n1 = 1; n1 < int(nums.size()); n1++)
            {
                if (nums[n] + nums[n1] == target)
                {
                    r.push_back(nums[n]);
                    r.push_back(nums[n1]);
                    return r;
                }
            }
        }
        return r;
    }
};
int main()
{
    std::vector<int> nums = {1, 2, 3, 5};
    int target = 5;
    Solution s;
    std::vector<int> r = s.twoSum(nums, target);
    for (auto &au : r)
    {
        std::cout << au << std::endl;
    }
    return 0;
}