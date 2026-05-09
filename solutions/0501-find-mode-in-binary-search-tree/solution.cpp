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
    int key;
public:
    void find(std::vector<int>& res, TreeNode* n, int& max, int& curry) {
        if (!n) return; 
        
        find(res, n->left, max, curry);
        


        if (key != n->val) {
            key = n->val;
            curry = 0;
        }

        ++curry;
        if (max < curry) {
            max = curry; 
            res.assign(1, key);
        } else if (max == curry) res.push_back(key);
        
        find(res, n->right, max, curry);
    }

    vector<int> findMode(TreeNode* root) {
        int max_count{};
        int curry_count{};
        std::vector<int> res;
        key = root->val;
        find(res, root, max_count, curry_count);

        return res;
    }
};
