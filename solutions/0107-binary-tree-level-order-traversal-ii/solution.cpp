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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};

        std::vector<std::vector<int>> res;
        int i{};
        std::queue<TreeNode*> q;
        
        q.push(root);

        while (!q.empty()) {
            std::queue<TreeNode*> tmp;
            res.push_back({});
            while (!q.empty()) {
                TreeNode* curr = q.front();
                q.pop();

                res[i].push_back(curr->val);

                if (curr->left) tmp.push(curr->left);
                if (curr->right) tmp.push(curr->right);
            }
                ++i;
                q = std::move(tmp);
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
