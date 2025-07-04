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
    unordered_map<Node*, Node*> cloned;
    Node* dfs(Node* node) {
        if(!node) return nullptr;
        if(cloned.find(node) != cloned.end()) {
            return cloned[node];
        }

        Node* copyNode = new Node(node->val);
        cloned[node] = copyNode;

        for(Node* node: node->neighbors) {
            copyNode->neighbors.push_back(dfs(node));
        }
        return copyNode;
    }
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};
