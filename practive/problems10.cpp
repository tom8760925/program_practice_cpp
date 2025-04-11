#include <vector>
#include <iostream>

class Solution
{
public:
    void moveZeroes(std::vector<int> &nums)
    {
        const int ns = nums.size();
        for (int n = 0; n < ns; n++)
        {
            if (nums[n] == 0)
            {
                nums.erase(nums.begin() + n);
                nums.push_back(0);
            }
        }
    }
};
int main()
{
    Solution s;
    std::vector<int> v = {0, 1, 0, 3, 12};
    s.moveZeroes(v);
    for (auto &au : v)
    {
        std::cout << au << std::endl;
    }
    return 0;
}