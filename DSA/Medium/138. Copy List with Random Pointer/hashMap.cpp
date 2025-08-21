/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

store random by the node as key, start from head create list through new ()
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodes;
        Node* temp = head;
        while(temp) {
            nodes[temp] = new Node(temp->val);
            temp = temp->next;
        }
        
        temp = head;
        while(temp) {
            nodes[temp]->next = nodes[temp->next];
            nodes[temp]->random = nodes[temp->random];
            temp = temp->next;
        }
        return nodes[head];
    }
};
