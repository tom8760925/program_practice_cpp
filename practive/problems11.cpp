#include <vector>
#include <iostream>

class Solution
{
public:
    int search(std::vector<int> &nums, int target)
    {
        int l = 0;
        // 減一是因為index會超過
        int r = nums.size() - 1;
        // 判斷l是否大於r，如果false的話就代表沒有收尋到。
        while (l <= r)
        {
            // 將陣列分為一半
            int m = (l + r) / 2;
            // 判斷m位置的值是否為收尋值
            if (nums[m] == target)
            {
                return m;
            }
            // 如果小於收尋值就代表值可能在右側，將l的值變為m+1的值
            if (nums[m] < target)
            {
                l = m + 1;
            }
            // 如果大於收尋值就代表值可能在左側 將r的值變為減掉已經判斷的值
            else
            {
                r = m - 1;
            }
        }
        // 如果都沒有返回-1
        return -1;
    }
};
int main()
{
    Solution s;
    std::vector<int> v = {-1, 0, 3, 5, 9, 12};
    std::cout << s.search(v, 3) << std::endl;
    return 0;
}