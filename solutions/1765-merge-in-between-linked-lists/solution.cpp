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
    ListNode* ListEnd(ListNode* head) {
        if (head == nullptr) return head;

        ListNode* curr = head;

        while (curr->next) {
            curr = curr->next;
        }
        return curr;
    }

public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr = list1;
        b = b - a + 1;

        while (--a) {
            curr = curr->next;
        }
        ListNode* Ath = curr;

        while (b--) {
            curr = curr->next;
        }
        ListNode* Bth = curr->next;
        curr->next = nullptr;

        ListNode* end2 = ListEnd(list2);

        Ath->next = list2;
        end2->next = Bth;

        return list1;
    }
};
