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
    ListNode* first(ListNode* head, int left) {
        ListNode* curr = new ListNode(0, head);
        while (--left) {
            curr = curr->next;
        }
        return curr;
    }

    void reverse(ListNode* first) {
        ListNode* curr = first;
        ListNode* prev = nullptr;

        while (curr->next != nullptr) {
            ListNode* n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;            
        }
        curr->next = prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || head->next == nullptr || left >= right) return head;

        ListNode* left_next = first(head, left);
        ListNode* reverse_last_elem = first(head, right)->next;

        ListNode* reverse_first_elem = left_next->next;
        left_next->next = nullptr;
        ListNode* r  = reverse_last_elem->next;
        reverse_last_elem->next = nullptr;

        reverse(reverse_first_elem);
    
        left_next->next = reverse_last_elem;
        reverse_first_elem->next = r;
        
        return left != 1 ? head : left_next->next;
    }
};
