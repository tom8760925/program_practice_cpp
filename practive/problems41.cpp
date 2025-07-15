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
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        std::vector<std::vector<int>> r = {};
        if (root == nullptr)
        {
            return {};
        }
        std::function<bool(struct TreeNode *, struct TreeNode *)> func = [&](struct TreeNode *rootl, struct TreeNode *rootr)
        {
            if (rootl == nullptr && rootr == nullptr)
            {
                return true;
            }

            if (rootl == nullptr || rootr == nullptr)
            {
                return false;
            }
            return rootl->val == rootr->val && func(rootl->left, rootr->right) && func(rootl->right, rootr->left);
        };
        b = func(root->left, root->right);
        return r;
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
    std::vector<int> nums = {1, 2, 2, 3, 4, 4, 3};
    struct TreeNode *root = settreeNode(nums);
    std::cout << s.isSymmetric(root) << std::endl;

    return 0;
}