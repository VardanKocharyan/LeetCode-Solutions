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
    ListNode* curr;

    TreeNode* build(int l, int r) {
        if (l > r) return nullptr;
        int m = l + (r - l) / 2;
        TreeNode* left = build(l, m - 1);
        TreeNode* nn = new TreeNode(curr->val);
        curr = curr->next;
        nn->left = left;
        nn->right = build(m + 1, r);
        return nn;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int n{};
        ListNode* nn = head;
        while (nn) {
            nn = nn->next;
            ++n;
        }
        curr = head;
        return build(0, n - 1);
    }
};
