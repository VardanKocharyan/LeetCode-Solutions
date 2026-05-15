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
private:
    int max = std::numeric_limits<int>::min();
public:
    int rec(TreeNode* n) {
        if (!n) return 0;
        int l = std::max(0, rec(n->left));
        int r = std::max(0, rec(n->right));

        if (l + n->val + r > max) max = l + n->val + r;

        return std::max(n->val, n->val + std::max(l, r));
    }

    int maxPathSum(TreeNode* root) {
        return std::max(max, rec(root));
    }
};
