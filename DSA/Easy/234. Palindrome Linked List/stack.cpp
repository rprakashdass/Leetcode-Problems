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
    bool isPalindrome(ListNode* head) {
        stack<int> stq;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            stq.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast) stq.push(slow->val);
        while(slow && !stq.empty()){
            if(slow->val != stq.top()) return false;
            stq.pop();
            slow = slow->next;
        }
        return stq.empty();
    }
};
