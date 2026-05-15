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
    TreeNode* build(std::vector<int>& pre, int l, int r) {
        if (l > r) return nullptr;
        int m = pre[k++];
        TreeNode* n = new TreeNode(m);
        n->left = build(pre, l, in_um[m] - 1);
        n->right = build(pre, in_um[m] + 1, r);
        return n;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i{}; i < inorder.size(); ++i) 
            in_um[inorder[i]] = i;

        return build(preorder, 0, inorder.size() - 1);
    }
};
