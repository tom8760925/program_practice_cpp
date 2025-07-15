#include <iostream>
#include <vector>
#include <string>
#include <functional>

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
    std::vector<int> inorderTraversal(struct TreeNode *root)
    {
        std::vector<int> nums = {};
        std::function<void(struct TreeNode *)> func = [&](struct TreeNode *root)
        {
            // 判斷是否到底
            if (root == nullptr)
            {
                return;
            }
            // 判斷左邊
            func(root->left);
            // 新增
            nums.push_back(root->val);
            // 判端右邊
            func(root->right);
        };
        // 執行
        func(root);
        return nums;
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
    std::vector<int> nums = {1, -1, 2, 3, -1, -1, -1};
    struct TreeNode *root = settreeNode(nums);
    for (auto au : s.inorderTraversal(root))
    {
        std::cout << au << std::endl;
    }

    return 0;
}