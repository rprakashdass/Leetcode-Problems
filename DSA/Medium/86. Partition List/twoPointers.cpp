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
        ListNode* greater = new ListNode(0);
        ListNode* lesser = new ListNode(0);

        ListNode* greaterPtr = greater;
        ListNode* lesserPtr = lesser;
        ListNode* tempHead = head;

        while(tempHead){
            if(tempHead->val < x){
                lesserPtr->next = tempHead;
                lesserPtr = lesserPtr->next;
            } else {
                greaterPtr->next = tempHead;
                greaterPtr = greaterPtr->next;
            }
            tempHead = tempHead->next;
        }
        
        greaterPtr->next = nullptr;
        lesserPtr->next = greater->next;
        return lesser->next;
    }
};
