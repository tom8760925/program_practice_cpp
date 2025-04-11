#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> r = {};
        int x = 0;
        int z = nums.size() - 1;
        while (z >= 2)
        {
            for (int y = 1; y < z; y++)
            {
                if (nums[x] + nums[y] == -nums[z])
                {
                    std::vector<int> rr = {nums[x], nums[y], nums[z]};
                    r.push_back(rr);
                }
            }
            z--;
        }
        return r;
    }
};
int main()
{
    Solution s;
    std::vector<int> v = {-1, 0, 1, 2, -1, -4};
    for (auto &au : s.threeSum(v))
    {
        for (auto &aut : au)
        {
            std::cout << aut << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}