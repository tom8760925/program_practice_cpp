#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    void nextPermutation(std::vector<int> &nums)
    {
        int l = 0;
        int r = 0;
        //1.由右至左收尋左邊小於右邊的第一個數字
        for (int n = int(nums.size()) - 2; n >= 0; n--)
        {
            if (nums[n] < nums[n + 1])
            {
                l = n;
                break;
            }
        }
        //2.由右至左收尋大於1.取得數字的第一個數字
        for (int n = int(nums.size()) - 1; n >= 0; n--)
        {
            if (nums[n] > l)
            {
                r = n;
                break;
            }
        }
        //3.兩者交換
        std::swap(nums[l], nums[r]);
        //4.將1.取得數字位置之後進行排序
        std::sort(nums.begin() + (l + 1), nums.end());
    }
};
int main()
{
    Solution s;
    std::vector<int> v = {3, 2, 1};
    s.nextPermutation(v);
    for (auto &au : v)
    {
        std::cout << au << std::endl;
    }
    return 0;
}