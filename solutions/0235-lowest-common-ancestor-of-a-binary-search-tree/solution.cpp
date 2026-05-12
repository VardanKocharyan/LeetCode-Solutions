/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* search(TreeNode* n, TreeNode* min, TreeNode* max) {
        if ((n->val == min->val || n->val == max->val)
            || (n->val > min->val && n->val < max->val)) return n;
        else if (n->val < min->val) return search(n->right, min, max);
        return search(n->left, min, max); 
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) std::swap(p, q);
        return search(root, p, q);
    }
};
