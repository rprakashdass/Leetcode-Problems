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
    inline ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* reversedhalf = reverse(slow);
        int maxSum = 0;
        fast = head;
        while(fast && reversedhalf){
            int twin1 = fast->val;
            int twin2 = reversedhalf->val;
            maxSum = max(maxSum, twin1 + twin2);
            fast = fast->next;
            reversedhalf = reversedhalf->next;
        }
        return maxSum;
    }
};
