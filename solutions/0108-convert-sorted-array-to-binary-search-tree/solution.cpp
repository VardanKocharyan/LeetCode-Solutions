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
    TreeNode* construct(std::vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;
        int m = l + (r - l) / 2;
        TreeNode* nn = new TreeNode(nums[m]);
        nn->left = construct(nums, l, m - 1);
        nn->right = construct(nums, m + 1, r);
        return nn;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return construct(nums, 0, nums.size() - 1);
    }
};
