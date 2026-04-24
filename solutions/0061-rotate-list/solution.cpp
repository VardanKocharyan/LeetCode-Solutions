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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* h1 = head;
        int count = k;
        
        while (count && h1->next) {
            h1 = h1->next;
            --count;
        }
        
        if (h1->next == nullptr && count != 0) {
            int size = k - count + 1;
            k = k % size;
            h1 = head;
            while (k--) {
                h1 = h1->next;
            }  
        }

        ListNode* h2 = head;
        while (h1->next != nullptr) {
            h1 = h1->next;
            h2 = h2->next;
        }

        h1->next = head;
        head = h2->next;
        h2->next = nullptr;
        return head;
    }
};
