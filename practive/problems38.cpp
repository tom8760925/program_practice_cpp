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
private:
    int dfs(TreeNode *node, int &res)
    {
        // 判斷是否到底了
        if (node == nullptr)
        {
            return 0;
        }
        // 收尋左右側值
        int leftSum = std::max(0, dfs(node->left, res));
        int rightSum = std::max(0, dfs(node->right, res));
        // 取得加總最大值，只要某的地方加總大於現今最大值就會自動替換
        res = std::max(res, leftSum + rightSum + node->val);
        // 回傳加總值
        return std::max(leftSum, rightSum) + node->val;
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int val = root->val;
        dfs(root, val);
        return val;
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
    std::vector<int> nums = {1, 2, 3};
    struct TreeNode *root = settreeNode(nums);
    std::cout << s.maxPathSum(root) << std::endl;

    return 0;
}