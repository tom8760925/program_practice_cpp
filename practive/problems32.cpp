#include <iostream>
#include <vector>
#include <string>

// 答案對但方式不符合
class Solution
{
public:
    int search(std::vector<int> &nums, int target)
    {
        for (int n = 0; n < nums.size(); n++)
        {
            if (nums[n] == target)
            {
                return n;
            }
        }

        return -1;
    }
};

// 用二元
class Solution1
{
public:
    int search(std::vector<int> &nums, int target)
    {
        // 設定左右
        int left = 0;
        int right = nums.size() - 1;

        // 判斷左小於或等於右
        while (left <= right)
        {
            // 取得中間值
            int mid = (left + right) / 2;

            // 判斷是否等於
            if (nums[mid] == target)
            {
                return mid;
            }
            // 判斷左邊小
            else if (nums[mid] >= nums[left])
            {
                // 判斷範圍是否在左和中間值之間
                if (nums[left] <= target && target <= nums[mid])
                {
                    // 將範圍限制到左邊
                    right = mid - 1;
                }
                else
                {
                    // 將範圍限制到右邊
                    left = mid + 1;
                }
            }
            // 判斷右邊小
            else
            {
                // 判斷範圍是否在右和中間值之間
                if (nums[mid] <= target && target <= nums[right])
                {
                    // 將範圍限制到右邊
                    left = mid + 1;
                }
                else
                {
                    // 將範圍限制到左邊
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution1 s;
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    std::cout << s.search(nums, 0) << std::endl;
    return 0;
}