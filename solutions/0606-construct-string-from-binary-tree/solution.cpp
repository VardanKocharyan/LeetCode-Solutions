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
    void dfs(TreeNode* n, std::string& s) {
        s.append(std::to_string(n->val));

        if (!n->left && !n->right) return;
        
        s.push_back('(');
        if (n->left) dfs(n->left, s);
        s.push_back(')');

        if (!n->right) return;
        s.push_back('(');
        dfs(n->right, s);
        s.push_back(')');
    }

    string tree2str(TreeNode* root) {
        std::string s;
        dfs(root, s);
        return s;
    }
};
