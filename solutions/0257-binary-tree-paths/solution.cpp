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
    std::vector<std::string> res;
public:
    void dfs(TreeNode* n, std::string s) {
        if (!n) return;

        s.append(std::to_string(n->val));
        if (!n->left && !n->right) {
            res.push_back(s);
            return;
        }

        dfs(n->left, s + "->");
        dfs(n->right, s + "->");
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root->left && !root->right) return {std::to_string(root->val)};
        
        std::string s;
        dfs(root, s);
        return res;
    }
};
