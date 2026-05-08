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
    void post(Node* n, std::vector<int>& res) {
        if (!n) return;
        for (Node* child : n->children) post(child, res);
        res.push_back(n->val);
    }

    vector<int> postorder(Node* root) {
        std::vector<int> res;
        post(root, res);
        return res;
    }
};
