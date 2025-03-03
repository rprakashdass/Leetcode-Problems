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
    ListNode* partition(ListNode* head, int x) {
        ListNode* result = new ListNode();
        ListNode* tempHead = head;
        ListNode* tempResult = result;
        while(tempHead){
            if(tempHead->val < x){
                cout << tempHead->val << " ";
                tempResult->next = new ListNode(tempHead->val);
                tempResult = tempResult->next;
            }
            tempHead = tempHead->next;
        }
        tempHead = head;
        while(tempHead){
            if(tempHead->val >= x){
                tempResult->next = new ListNode(tempHead->val);
                tempResult = tempResult->next;
            }
            tempHead = tempHead->next;
        }
        return result->next;
    }
};
