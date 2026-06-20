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
    TreeNode* REL(TreeNode* n) {
        if (!n) return n;
        
        TreeNode* r = n->right;
        n->right = n->left;
        n->left = nullptr;
        
        TreeNode* currl = REL(n->right);
        if(!currl) currl = n;
        if(!r) return currl;
        
        currl->right = r;
        TreeNode* currr = REL(r);
        
        return currr ? currr : r;
        
    }
    
    void flatten(TreeNode* root) {
        TreeNode* tmp = REL(root);
        //std::cout << tmp->val;
    }
};
