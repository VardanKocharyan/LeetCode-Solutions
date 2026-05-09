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
    TreeNode* prev = nullptr;
public:
    int getMinimumDifference(TreeNode* root) {
        if (!root) return std::numeric_limits<int>::max();

        int min_l = getMinimumDifference(root->left);

        if (prev && std::abs(prev->val - root->val) < min_l) min_l = std::abs(prev->val - root->val);

        prev = root;

        int min_r = getMinimumDifference(root->right);
        return std::min(min_l, min_r);
    }
};
