#include <deque>

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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr) { return nullptr; }
        std::deque<TreeNode *> d;
        d.push_back(root);
        while (!d.empty())
        {
            auto node = d.front();
            d.pop_front();
            if (node == nullptr) { continue; }
            if (node->left) { d.push_back(node->left); }
            std::swap(node->left, node->right);
            if (node->left) { d.push_back(node->left); }
        }
        return root;
    }
};