#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
    {
        // 轉成一維
        std::vector<int> nums = {};
        for (auto au : matrix)
        {
            for (auto aut : au)
            {
                nums.push_back(aut);
            }
        }
        // 收尋
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
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    std::cout << s.searchMatrix(matrix, 3) << std::endl;
    return 0;
}