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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* curr = &dummy;

        while (curr->next && curr->next->next) {
            if (curr->next->val == curr->next->next->val) {
                int key = curr->next->val;
                while (curr->next && curr->next->val == key) {
                    ListNode* n = curr->next->next;
                    curr->next->next = nullptr;
                    curr->next = n;
                }
            } else {
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};
