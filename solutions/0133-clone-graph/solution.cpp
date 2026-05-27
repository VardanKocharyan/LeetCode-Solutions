/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* makeGraph(Node* node, std::vector<Node*>& visited) {
        Node* new_node = new Node(node->val);
        visited[node->val - 1] = new_node;

        for (Node* ch : node->neighbors) {
            if (!visited[ch->val - 1]) {
                new_node->neighbors.push_back(std::move(makeGraph(ch, visited)));
            } else {
                new_node->neighbors.push_back(visited[ch->val - 1]);
            }
        }

        return new_node;
    }

    Node* cloneGraph(Node* node) {
        if (!node) return node;
        std::vector<Node*> visited(101, nullptr);     
        return makeGraph(node, visited);
    }
};
