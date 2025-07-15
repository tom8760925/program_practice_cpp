#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
private:
    void permuteswap(std::vector<std::vector<int>> &r, std::vector<int> &nums, int n)
    {
        if (n == int(nums.size()))
        {
            r.push_back(nums);
            return;
        }
        for (int i = n; i < int(nums.size()); i++)
        {
            std::swap(nums[n], nums[i]);
            permuteswap(r, nums, n + 1);
            std::swap(nums[n], nums[i]);
        }
    }

public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> r = {};
        permuteswap(r, nums, 0);
        return r;
    }
};
int main()
{
    Solution s;
    std::vector<int> n = {1, 2, 3, 4};
    for (auto au : s.permute(n))
    {
        for (auto aut : au)
        {
            std::cout << aut << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}