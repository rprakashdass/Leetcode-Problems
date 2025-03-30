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
        ListNode* temp = head;
        int totalSize = 0;
        while(temp){
            totalSize++;
            temp = temp->next;
        }
        if(n == totalSize) return head->next;
        temp = head;
        int removeTill = totalSize - n;
        ListNode* prev = head;
        while(removeTill-- && temp){
            prev = temp;
            temp = temp->next;
        }
        ListNode* deleteNode = prev->next;
        prev->next = prev->next->next;
        delete deleteNode;
        return head;
    }
};
