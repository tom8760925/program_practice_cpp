#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// 簡單版
class Solution
{
public:
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::vector<int> nums = {};
        // 新增陣列
        std::copy(nums1.begin(), nums1.end(), std::back_inserter(nums));
        std::copy(nums2.begin(), nums2.end(), std::back_inserter(nums));
        // 排序陣列
        std::sort(nums.begin(), nums.end());
        // 中間值
        int m = nums.size() / 2;
        if (nums.size() % 2)
        {
            return nums[m];
        }
        else
        {
            return double(nums[m] + nums[m - 1]) / 2.0;
        }

        return 0;
    }
};

// 運算
class Solution1
{
public:
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::vector<int> nums = {};
        int r = 0, c = 0, n = 0;
        int lenr = nums1.size();
        int lenc = nums2.size();

        // 判斷是否為單一陣列
        if (lenr == 0)
        {
            nums = nums2;
        }
        else if (lenc == 0)
        {
            nums = nums1;
        }
        else
        {
            // 跑兩個陣列總和
            while (n < (lenr + lenc))
            {
                // 判斷兩個陣列是否不為底
                if (r != lenr && c != lenc)
                {
                    // 判斷大小
                    if (nums1[r] < nums2[c])
                    {
                        nums.push_back(nums1[r++]);
                    }
                    else
                    {
                        nums.push_back(nums2[c++]);
                    }
                }
                // r陣列不為底
                else if (r < lenr)
                {
                    nums.push_back(nums1[r++]);
                }
                // c陣列不為底
                else
                {
                    nums.push_back(nums2[c++]);
                }
                n++;
            }
        }
        // 中間值
        int m = nums.size() / 2;
        if (nums.size() % 2)
        {
            return nums[m];
        }
        else
        {
            return double(nums[m] + nums[m - 1]) / 2.0;
        }

        return 0;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    std::vector<int> nums2 = {6, 7, 8, 9, 10};
    std::cout << s.findMedianSortedArrays(nums1, nums2) << std::endl;
    return 0;
}