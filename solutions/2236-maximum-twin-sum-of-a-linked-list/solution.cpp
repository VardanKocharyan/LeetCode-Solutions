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
    ListNode* getMid(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* curr = slow->next;
        slow->next = nullptr;
        return curr;
    }

    ListNode* reverse(ListNode* curr) {
        ListNode* prev = nullptr;

        while (curr) {
            ListNode* n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        return prev;
    }

    int getMax(ListNode* f, ListNode* s) {
        int max = std::numeric_limits<int>::min();
        while (f) {
            max = std::max(max, f->val + s->val);
            f = f->next;
            s = s->next;
        }
        return max;
    }

    int pairSum(ListNode* head) {
        return getMax(reverse(getMid(head)), head);
    }
};
