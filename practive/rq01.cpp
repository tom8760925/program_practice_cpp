#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target) // 第一版本兩個數字相加
    {
        vector<int> r;
        for (unsigned long n = 0; n < nums.size(); n++)
        {
            if (nums[n] > target) // 判斷數字是否大於目標數
            {
                continue;
            }
            for (unsigned long i = 1; i < nums.size(); i++) // 相加
            {
                if (nums[n] + nums[i] == target)
                {
                    return {nums[n], nums[i]};
                }
            }
        }
        return {};
    }
    vector<int> twoSum2(vector<int> &nums, int target) // 第二版本改成用函數
    {
        vector<int> r = twosum_filter(nums, target);
        return twosum_judge(r, target);
    }
    vector<int> twoSum3(vector<int> &nums, int target) // 第三版本新增排序
    {
        vector<int> nums_sort = twosum_sort(nums);
        vector<int> r = twosum_filter(nums_sort, target);
        return twosum_judge(r, target);
    }

private:
    vector<int> twosum_sort(vector<int> &nums) // 排序
    {
        vector<int> r = nums;
        int len = nums.size();
        int rr = 0;
        while (len > 1)
        {
            for (int i = 0; i < len - 1; i++)
            {
                if (r[i] > r[i + 1])
                {
                    rr = r[i];
                    r[i] = r[i + 1];
                    r[i + 1] = rr;
                }
            }
            len--;
        }
        return r;
    }
    vector<int> twosum_filter(vector<int> &nums, int target) // 判斷數字是否大於目標數
    {
        vector<int> r = {};
        for (unsigned long n = 0; n < nums.size(); n++)
        {
            if (nums[n] < target)
            {
                r.push_back(nums[n]);
            }
        }
        return r;
    }
    vector<int> twosum_judge(vector<int> &nums, int target) // 相加
    {
        for (unsigned long n = 0; n < nums.size(); n++)
        {
            for (unsigned long i = 1; i < nums.size(); i++)
            {
                if (nums[n] + nums[i] == target)
                {
                    return {nums[n], nums[i]};
                }
            }
        }
        return {};
    }
};
int main()
{
    Solution s;

    vector<int> nums = {11, 7, 15, 2};
    vector<int> v = s.twoSum3(nums, 9);
    if (v.empty()) // 判斷是否資料
    {
        printf("p:\n");
    }
    else
    {
        printf("p:");
        for (unsigned long n = 0; n < v.size(); n++)
        {
            cout << v[n];
            if (n < v.size() - 1)
            {
                cout << "、";
            }
        }
        cout << endl;
    }

    return 0;
}