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
    vector<vector<int>> levelOrder(Node* root) {
        std::vector<std::vector<int>> res;
        if (!root) return res;

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            std::vector<int> tmp;
            int s = q.size();
            
            for (int i{}; i < s; ++i) {
                Node* n = q.front(); q.pop();
                tmp.push_back(n->val);

                for (int i{}; i < n->children.size(); ++i) {
                    q.push(n->children[i]);
                }
            }
            res.push_back(std::move(tmp));
        }
        return res;
    }
};
