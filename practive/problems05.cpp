#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int searchInsert(std::vector<int> &nums, int target)
    {
        std::sort(nums.begin(), nums.end());
        for (int n = 0; n < int(nums.size()); n++)
        {
            if (nums[n] >= target)
            {
                return n;
            }
        }
        return nums.size();
    }
};
int main()
{
    std::vector<int> v = {1, 3, 5, 6};
    int target = 7;
    Solution s;
    std::cout << s.searchInsert(v, target) << std::endl;
    return 0;
}