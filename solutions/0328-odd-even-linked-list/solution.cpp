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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode();
        ListNode* even = new ListNode();

        ListNode* o = odd;
        ListNode* e = even;
        bool odd_even = false;

        while (head) {
            
            ListNode* n = head;
            head = head->next;
            n->next = nullptr;

            if (odd_even) {
                e->next = n;
                e = e->next;
                odd_even = !odd_even;
            } else {
                o->next = n;
                o = o->next;
                odd_even = !odd_even;
            }
        }

        o->next = even->next;

        return odd->next;
    }
};
