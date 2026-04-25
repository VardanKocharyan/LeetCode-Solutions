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
private:
    ListNode* Kthbegin(ListNode* head, int k) {
        ListNode* dummy = head;
        while (--k != 0) {
            dummy = dummy->next;
        }
        return dummy;
    }

    ListNode* Kthend(ListNode* head, ListNode* kth) {
        ListNode* ptr1 = kth->next;
        ListNode* ptr2 = head;
        while (ptr1->next != nullptr) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr2;
    }

public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* a = Kthbegin(&dummy, k);
        ListNode* b = Kthend(&dummy, a);

        ListNode* tmp = a->next;
        a->next = b->next;
        b->next = tmp;

        tmp = a->next->next;
        a->next->next = b->next->next;
        b->next->next = tmp;

        return dummy.next;
    }
};
