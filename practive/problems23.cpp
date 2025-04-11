#include <iostream>
#include <vector>

class Solution
{
public:
    bool canJump(std::vector<int> &nums)
    {
        int l = 0;
        int r = 0;
        while (r < int(nums.size()) - 1)
        {
            int ind = 0;
            for (int n = l; n <= r; n++)
            {
                ind = std::max(nums[n] + n, ind);
            }
            if (ind == 0)
            {
                return false;
            }
            l = r + 1;
            r = ind;
        }
        return true;
    }
};
int main()
{
    Solution s;
    std::vector<int> v = {3, 2, 1, 0, 4};
    std::cout << s.canJump(v) << std::endl;
    return 0;
}