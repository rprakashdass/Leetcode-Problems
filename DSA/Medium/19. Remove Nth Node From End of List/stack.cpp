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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> stq;
        ListNode* temp = head, *nodeToDel = nullptr;
        while(temp){
            stq.push(temp);
            temp = temp->next;
        }
        if(n == 1){
            if(head == stq.top()) {
                head = nullptr;
            } else {
                stq.pop();
                stq.top()->next = nullptr;
            }
            return head;
        }
        while(!stq.empty() && n--){
            nodeToDel = stq.top();
            stq.pop();
        }
        if(nodeToDel->next){
            nodeToDel->val = nodeToDel->next->val;
            nodeToDel->next = nodeToDel->next->next;
        }
        return head;
    }
};
