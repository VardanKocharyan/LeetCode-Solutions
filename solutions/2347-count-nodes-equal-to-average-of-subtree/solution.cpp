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
    int res{0};
public:
    std::pair<int, int> solve(TreeNode* n) {
        if (!n) return {0, 0};
        
        std::pair<int, int> l = solve(n->left);
        std::pair<int, int> r = solve(n->right);

        int sum   = n->val + l.second + r.second;
        int count = 1 + l.first + r.first;

        if (n->val == (sum / count)) ++res;

        return {count, sum};
   }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return res;
    }
};
