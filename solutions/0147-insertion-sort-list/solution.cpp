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
    ListNode* insertionSortList(ListNode* head) {
        if (head->next == nullptr) return head;

        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = dummy->next;
        head = head->next;
        curr->next = nullptr;

        while (head) {

            ListNode* n = head;
            head = head->next;

            if (curr->val <= n->val) {
                curr->next = n;
                curr = curr->next;
                curr->next = nullptr;
            } else {
                ListNode* j = dummy;
                while (j->next != curr) {
                    if (j->next->val >= n->val) break;
                    j = j->next;
                }
                n->next = j->next;
                j->next = n;
            }
        }
        return dummy->next;
    }
};
