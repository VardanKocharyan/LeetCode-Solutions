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
    std::vector<int> res;
public:
    void helper(TreeNode* n) {
        if (!n) return;
        helper(n->left);
        helper(n->right);
        res.push_back(n->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        helper(root);
        return res;
    }
};
