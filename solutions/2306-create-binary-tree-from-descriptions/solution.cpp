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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        std::unordered_map<int, std::pair<bool, TreeNode*>> mp;

        for (const auto& e : descriptions) {
            int p = e[0];
            int c = e[1];
            int d = e[2];

            if (!mp.contains(p)) {
                mp[p].first = true;
                mp[p].second = new TreeNode(p);
            }

            if (!mp.contains(c)) {
                mp[c].second = new TreeNode(c);
            }

            mp[c].first = false;
            if (d) mp[p].second->left = mp[c].second;
            else mp[p].second->right = mp[c].second;
        }

        for (const auto& [key, value] : mp) {
            if (value.first) return value.second;
        }

        return nullptr;
        
    }
};
