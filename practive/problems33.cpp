#include <iostream>
#include <vector>
#include <string>

class Solution
{
private:
    int searchbool(std::vector<int> &nums, int target, bool booll)
    {
        int n = -1;
        int l = 0;
        int r = nums.size() - 1;
        // 迴圈
        while (l <= r)
        {
            // 中間值
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
                n = m;
                // 判斷是否為最左邊
                if (booll)
                {
                    r = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
        }
        return n;
    }

public:
    std::vector<int> searchRange(std::vector<int> &nums, int target)
    {
        std::vector<int> rnums(2);
        // 執行
        rnums[0] = searchbool(nums, target, true);
        rnums[1] = searchbool(nums, target, false);
        return rnums;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = {5, 7, 7, 8, 8, 10};
    for (auto au : s.searchRange(nums, 8))
    {
        std::cout << au << std::endl;
    }
    return 0;
}