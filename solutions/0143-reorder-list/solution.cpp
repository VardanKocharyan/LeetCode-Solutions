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
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr) {
            ListNode* n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        return prev;
    }

    ListNode* mid(ListNode* n) {
        ListNode* fast = n;
        ListNode* slow = n;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    void merge(ListNode* list1, ListNode* list2) {
        ListNode* curr = list1;

        while (list2) {
            ListNode* n = list2->next;

            list2->next = curr->next;
            curr->next = list2;
            list2 = n;

            curr = curr->next->next;
        }
    }
public:
    void reorderList(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);

        ListNode* m = mid(dummy);
        ListNode* head2 = m->next;
        m->next = nullptr;

        head2 = reverse(head2);

        merge(head, head2);
    }
};
