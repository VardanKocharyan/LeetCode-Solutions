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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<vector<int>> res;
        if (!root) return res;

        std::queue<TreeNode*> q;
        bool f = true;

        q.push(root);

        while (!q.empty()) {
            int s = q.size();            
            std::vector<int> tmp(s);

            for (int i{}; i < s; ++i) {
                TreeNode* n = q.front(); q.pop();
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);

                tmp[f ? i : s - i - 1] = n->val;
            }
            res.push_back(std::move(tmp));
            f =!f;
        }
        return res;
    }
};
