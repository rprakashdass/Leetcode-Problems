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
        while(!stq.empty() && n--){
            nodeToDel = stq.top();
            stq.pop();
        }
        if(stq.empty()) return head->next;
        ListNode* prev = stq.top();
        prev->next = nodeToDel->next;
        return head;
    }
};
