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
/*
    Steps:
    1. Move the fastPtr pointer n+1 nodes ahead.
    2. Now move slowPtr and fastPtr at the same speed (1 step each).
    3. When fastPtr reaches the end, slowPtr will be right before the node to be deleted.
 */
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyNode = new ListNode();
        dummyNode->next = head;
        
        ListNode *slowPtr = dummyNode, *fastPtr = dummyNode;

        // Move fastPtr n+1 steps ahead
        for(int i = 0; i <= n && fastPtr; i++) 
            fastPtr = fastPtr->next;

        // Move both pointers until fastPtr reaches the end
        while(fastPtr) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }

        // Delete the nth node from the end
        ListNode* nodeToDelete = slowPtr->next;
        slowPtr->next = slowPtr->next->next;
        delete nodeToDelete;

        return dummyNode->next;
    }
};
