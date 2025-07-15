#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
    int searchInsert(std::vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] > target)
            {
                r = m - 1;
            }
            else if (nums[m] < target)
            {
                l = m + 1;
            }
            else
            {
                return m;
            }
        }
        // 因為題目找不到要給索引所以回傳l
        return l;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = {1, 3, 5, 6};
    std::cout << s.searchInsert(nums, 5) << std::endl;
    return 0;
}