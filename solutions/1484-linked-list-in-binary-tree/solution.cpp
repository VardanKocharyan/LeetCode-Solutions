/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool dfs(ListNode* h, TreeNode* n) {
        if (!h) return true;
        if (!n) return false;

        if (n->val == h->val && (dfs(h->next, n->left) || dfs(h->next, n->right))) return true;

        return false;
    }

    bool helper(ListNode* h, TreeNode* n) {
        if (!n) return false;
        if (dfs(h, n)) return true;
        return helper(h, n->left) || helper(h, n->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        return helper(head, root);
    }
};
