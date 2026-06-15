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
    ListNode* MergeSort(ListNode* left, ListNode* right) {
        ListNode dummy;
        ListNode* curr = &dummy;

        while (left && right) {
            if (left->val < right->val) {
                curr->next = left;
                left = left->next;
            } else {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }

        curr->next = left ? left : right;

        return dummy.next;
        }

    ListNode* Merge(int l, int r, std::vector<ListNode*>& lists) {
        if (l >= r) {
            return lists[l];
        }

        int m = l + (r - l) / 2;

        ListNode* left = Merge(l, m, lists);
        ListNode* right = Merge(m + 1, r, lists);

        return MergeSort(left, right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        int l{}, r = lists.size() - 1;
        ListNode* res = Merge(l, r, lists);
        return res;
    }
};
