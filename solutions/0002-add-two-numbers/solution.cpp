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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int curry{};
        ListNode dummy;
        ListNode* curr = &dummy;
        curr->next = l1;

        while (l1 && l2) {
            int sum = l1->val + l2->val + curry;
            curr->next->val = sum % 10;
            curry = sum / 10;

            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        curr->next = l1 ? l1 : l2;

        while (curr->next) {
            if (curr->next->val == 9 && curry) curr->next->val = 0;
            else {
                curr->next->val += curry;
                curry = 0;
                return dummy.next;
            }
            curr = curr->next;
        }
        
        if (curry) curr->next = new ListNode(curry);
        return dummy.next;
    }
};
