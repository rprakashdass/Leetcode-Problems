/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, bool> visited;
        ListNode* temp = head;
        while(temp){
            if(visited[temp]) return temp;
            visited[temp] = true;
            temp = temp->next;
        }
        return nullptr;
    }
};
