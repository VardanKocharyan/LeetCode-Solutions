/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void pre(Node* n, std::vector<int>& res) {
        if (!n) return;

        res.push_back(n->val);
        for (Node* child : n->children) {
            pre(child, res);
        }
    }

    vector<int> preorder(Node* root) {
        std::vector<int> res;
        pre(root, res);
        return res;
    }
};
