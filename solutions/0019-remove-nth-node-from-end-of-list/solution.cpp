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
    ListNode* NthNodeFromEnd(ListNode* dummy, int n) {

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        for (int i{}; i < n; ++i) {
            fast = fast->next;
        }

        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* removed_prev = NthNodeFromEnd(dummy, n);

        ListNode* removed = removed_prev->next;
        
        removed_prev->next = removed->next;
        removed->next = nullptr;
        delete removed;

        return dummy->next;
    }
};
