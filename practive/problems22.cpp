#include <iostream>
#include <vector>

class Solution
{
public:
    int jump(std::vector<int> &nums)
    {
        int jumps = 0;
        int l = 0;
        int r = 0;
        while (r < int(nums.size()) - 1)
        {
            int ind = 0;
            for (int n = l; n <= r; n++)
            {
                ind = std::max(nums[n] + n, ind);
            }
            l = r + 1;
            r = ind;
            jumps++;
        }
        return jumps;
    }
};
int main()
{
    Solution s;
    std::vector<int> v = {2, 3, 1, 1, 4};
    std::cout << s.jump(v) << std::endl;
    return 0;
}