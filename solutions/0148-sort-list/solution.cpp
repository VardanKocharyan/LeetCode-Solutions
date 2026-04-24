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

    ListNode* middle(ListNode* l) {
        ListNode* fast = new ListNode(0, l);
        ListNode* slow = fast;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* n = slow->next;
        slow->next = nullptr;

        return n;
    }

    ListNode* merge(ListNode* l, ListNode* r) {
        if (!l) return r;
        if (!r) return l;

        ListNode* sentinel = new ListNode();
        ListNode* dummy = sentinel;

        while (l && r) {
            if (l->val <= r->val) {
                dummy->next = l;
                l = l->next;
            } else {
                dummy->next = r;
                r = r->next; 
            }
            dummy = dummy->next;    
        }

        dummy->next = l ? l : r;
        return sentinel->next;
    }

    ListNode* mergeSort(ListNode* l) {
        if (l == nullptr || l->next == nullptr) return l;

        ListNode* r = middle(l);
        r = mergeSort(r);
        l = mergeSort(l);

        return merge(l, r);
    }

    ListNode* sortList(ListNode* head) {
        head = mergeSort(head);
        return head;
    }
};
