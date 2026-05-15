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
    std::vector<std::vector<int>> res;
public:
    void path(TreeNode* n, int t, std::vector<int>& tmp) {
        if (!n) return;

        if (!n->left && !n->right) {
            if (n->val == t) {
                tmp.push_back(n->val);
                res.push_back(tmp);
                tmp.pop_back();
            }
            return;
        }

        tmp.push_back(n->val);
        path(n->left, t - n->val, tmp);
        path(n->right, t - n->val, tmp);
        tmp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        std::vector<int> tmp;
        path(root, targetSum, tmp);

        return res;
    }
};
