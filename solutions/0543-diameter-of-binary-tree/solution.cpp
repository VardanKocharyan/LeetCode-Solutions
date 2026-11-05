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
    int ans{};
public:
    int solve(TreeNode *n) {
        if (!n) return 0;

        int left = solve(n->left);
        int right = solve(n->right);

        ans = std::max(ans, left + right);

        return std::max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        return std::max(solve(root) - 1, ans);
    }
};
