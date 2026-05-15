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
    std::unordered_map<int, int> post_u;
    int idx{};
public:
    TreeNode* build(std::vector<int>& pre, int l, int r) {
        if (l > r) return nullptr;
        if (r == l) return new TreeNode(pre[idx++]);
        
        TreeNode* n = new TreeNode(pre[idx++]);
        int m = post_u[pre[idx]];
        n->left = build(pre, l, m);
        n->right = build(pre, m + 1, r - 1);
        return n;
    }

    void pushPost(std::vector<int>& post) {
        for (int i{}; i < post.size(); ++i) post_u[post[i]] = i;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        pushPost(postorder);

        return build(preorder, 0, postorder.size() - 1);
    }
};
