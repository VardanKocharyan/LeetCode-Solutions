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
    std::unordered_map<int, int> in_um;
    int k{};

public:
    TreeNode* build(std::vector<int>& post, int l, int r) {
        if (l > r || k >= post.size()) return nullptr;
        
        int m = post[post.size() - (k++) - 1];
        TreeNode* n = new TreeNode(m);
        n->right = build(post, in_um[m] + 1, r);
        n->left = build(post, l, in_um[m] - 1);
       
        return n;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i{}; i < inorder.size(); ++i) in_um[inorder[i]] = i;
        return build(postorder, 0, inorder.size() - 1);
    }
};
