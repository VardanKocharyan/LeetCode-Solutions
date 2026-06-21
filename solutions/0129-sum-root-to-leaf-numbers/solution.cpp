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
    int res{};

public:
    void dfs(TreeNode* n, int sum) {
        if (!n) return;
        if (!n->left && !n->right) {
            res += sum + n->val; 
            return;
        }

        dfs(n->left, (sum + n->val) * 10);
        dfs(n->right, (sum + n->val) * 10);
    }

    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};
