#include <iostream>
#include <vector>
#include <string>
#include <functional>

// 鏈結結構
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 建立二叉樹
struct Node *settreeNode(std::vector<int> &nums)
{
    Node *root = nullptr;
    int idx = 0;
    std::function<struct Node *(std::vector<int> &)> func = [&](std::vector<int> &nums) -> struct Node *
    {
        if (idx >= nums.size() || nums[idx] == -1)
        {
            idx++;
            return nullptr;
        }
        struct Node *root = new Node(nums[idx]);
        idx++;
        root->left = func(nums);
        root->right = func(nums);
        return root;
    };
    root = func(nums);
    return root;
}

// 顯示二叉樹
void shownode(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    shownode(root->left);
    std::cout << root->val << " ";
    shownode(root->right);
}

// 收尋二叉樹
bool searchnode(Node *root, int n)
{
    if (root == nullptr)
    {
        return false;
    }
    else if (root->val == n)
    {
        return true;
    }
    else if (searchnode(root->left, n))
    {
        return true;
    }
    else if (searchnode(root->right, n))
    {
        return true;
    }

    return false;
}

// 釋放二叉樹
void deletenode(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    deletenode(node->left);
    deletenode(node->right);
    delete node;
}

int main()
{
    std::vector<int> nums = {1, -1, 2, 3, -1, -1, -1};
    struct Node *root = settreeNode(nums);
    shownode(root);
    std::cout << std::endl;
    std::cout << searchnode(root, 3) << std::endl;
    deletenode(root);
    return 0;
}