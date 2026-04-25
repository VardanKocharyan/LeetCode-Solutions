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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            fast = fast->next->next;
            
            ListNode* n = slow->next;
            slow->next = prev;
            prev = slow;
            slow = n;
        }

        if (fast != nullptr) slow = slow->next;

        while (slow && prev) {
            if (slow->val != prev->val) return false;
            slow = slow->next;
            prev = prev->next;
        }

        return true;
    }
};
