/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getHeight(TreeNode* node) {
        if (!node) return 0;
        int l = getHeight(node->left);
        int r = getHeight(node->right);

        if (l == -1 || r == -1 || std::abs(l - r) > 1) return -1;

        return 1 + std::max(l, r);
    }

    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }
};
