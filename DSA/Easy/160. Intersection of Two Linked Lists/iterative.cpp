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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, bool> visited;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while(tempA) {
            visited[tempA] = true;
            tempA = tempA->next;
        }
        while(tempB) {
            if(visited[tempB]) return tempB;
            visited[tempB] = true;
            tempB = tempB->next;
        }
        return nullptr;
    }
};
