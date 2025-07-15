#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
    int findMin(std::vector<int> &nums)
    {
        int r = 0;
        if (nums.size() == 0)
        {
            return 0;
        }
        for (int n = 0; n < int(nums.size()) - 1; n++)
        {
            for (int nn = n + 1; nn < int(nums.size()); nn++)
            {
                if (nums[n] > nums[nn])
                {
                    r = nums[n];
                    nums[n] = nums[nn];
                    nums[nn] = r;
                }
            }
        }
        return nums[0];
    }
};

class Solution2
{
public:
    int findMin(std::vector<int> &nums)
    {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] <= nums[r])
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }

        return nums[l];
    }
};

int main()
{
    Solution2 s;
    std::vector<int> nums = {3, 4, 5, 1, 2};
    std::cout << s.findMin(nums) << std::endl;
    return 0;
}