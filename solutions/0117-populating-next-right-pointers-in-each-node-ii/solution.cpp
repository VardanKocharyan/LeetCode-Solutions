/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;

        Node* lvl = root;
        Node dummy(0);
        Node* curr = &dummy;
        while (lvl) {
            if (lvl->left) {
                curr->next = lvl->left;
                curr = curr->next;
            }
            if (lvl->right) {
                curr->next = lvl->right;
                curr = curr->next;
            }
            if (!lvl->next) {
                lvl = dummy.next;
                curr = &dummy;
                dummy.next = nullptr;
                continue;
            }
            lvl = lvl->next;
        }
        return root;
    }
};
