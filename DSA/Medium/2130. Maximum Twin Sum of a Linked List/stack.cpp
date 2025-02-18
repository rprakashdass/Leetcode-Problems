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
    int pairSum(ListNode* head) {
        stack<int> stq;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            stq.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        int maxSum = 0;
        while(slow && !stq.empty()){
            int stqData = stq.top();
            int nodeData = slow->val;
            stq.pop();
            maxSum = max(maxSum, stqData + nodeData);
            slow = slow->next;
        }
        return maxSum;
    }
};
