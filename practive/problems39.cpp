#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        bool b = false;
        std::function<bool(struct TreeNode *, long, long)> func = [&](struct TreeNode *root, long minimum, long maximum)
        {
            // 判斷是否到底
            if (root == nullptr)
            {
                return true;
            }
            // 判斷是否在範圍內
            if (!(root->val > minimum && root->val < maximum))
            {
                return false;
            }
            // 判斷左右節點
            return func(root->left, minimum, root->val) && func(root->right, root->val, maximum);
        };
        b = func(root, LONG_MIN, LONG_MAX);
        return b;
    }
};

// 建立二叉樹
struct TreeNode *settreeNode(std::vector<int> &nums)
{
    struct TreeNode *root = nullptr;
    int idx = 0;
    std::function<struct TreeNode *(std::vector<int> &)> func = [&](std::vector<int> &nums) -> struct TreeNode *
    {
        if (idx >= nums.size() || nums[idx] == -1)
        {
            idx++;
            return nullptr;
        }
        struct TreeNode *root = new TreeNode(nums[idx]);
        idx++;
        root->left = func(nums);
        root->right = func(nums);
        return root;
    };
    root = func(nums);
    return root;
}

int main()
{
    Solution s;
    std::vector<int> nums = {2, 1, 3};
    struct TreeNode *root = settreeNode(nums);
    std::cout << s.isValidBST(root) << std::endl;

    return 0;
}