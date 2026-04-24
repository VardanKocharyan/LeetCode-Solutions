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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode();
        ListNode* l = less;
        ListNode* greaterEqual = new ListNode();
        ListNode* ge = greaterEqual;

        while (head != nullptr) {
            if (head->val < x) {
                l->next = head;
                l = l->next;
            } else {
                ge->next = head;
                ge = ge->next;
            }
            head = head->next;
        }

        ge->next = nullptr;
        l->next = greaterEqual->next;
        delete greaterEqual;

        return less->next;
    }
};
