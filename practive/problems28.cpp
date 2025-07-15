#include <iostream>
#include <vector>
#include <string>

class Solution
{
private:
    void subsetsany(std::vector<std::vector<int>> &rsubsets, std::vector<int> &subset, std::vector<int> &nums, int n)
    {
        // 判斷是否到底
        if (n == int(nums.size()))
        {
            rsubsets.push_back(subset);
            return;
        }
        // 新增
        subset.push_back(nums[n]);
        // 下一步
        subsetsany(rsubsets, subset, nums, n + 1);
        // 移除
        subset.pop_back();
        // 下一步
        subsetsany(rsubsets, subset, nums, n + 1);
    }

public:
    std::vector<std::vector<int>> subsets(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> rsubsets = {};
        std::vector<int> subset = {};
        // 開始
        subsetsany(rsubsets, subset, nums, 0);
        return rsubsets;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = {1, 2, 3};
    for (auto au : s.subsets(nums))
    {
        std::cout << "[";
        for (auto aut : au)
        {
            std::cout << aut << ",";
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}