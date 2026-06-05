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
    std::pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* prev) {
        ListNode* curr = head;
        ListNode* finish = head;
        while (curr) {
            ListNode* n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        head = prev;
        return {head, finish};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode dummy(0, head);
       ListNode* start = &dummy;
       ListNode* curr = start->next;
       ListNode* prev = nullptr;

        while (curr) {
            int count = k;

            while (--count && curr) {
                curr = curr->next;
            }

            if (!curr) break;

            ListNode* n = curr->next;
            curr->next = nullptr;
            auto [h, f] = reverse(start->next, n);

            start->next = h;
            f->next = n; 

            start = f;
            curr = start->next;
        }

        head = dummy.next;

        return head;
    }
};
