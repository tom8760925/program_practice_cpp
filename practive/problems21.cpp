#include <iostream>
#include <vector>

class Solution
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        int rsum = 0;
        int r = 0;
        for (auto &au : nums)
        {
            rsum += au;
            if (rsum < 0)
            {
                rsum = 0;
            }
            if (r < rsum)
            {
                r = rsum;
            }
        }
        return r;
    }
};
int main()
{
    Solution s;
    std::vector<int> v = {5, 4, -1, 7, 8};
    std::cout << s.maxSubArray(v) << std::endl;
    return 0;
}