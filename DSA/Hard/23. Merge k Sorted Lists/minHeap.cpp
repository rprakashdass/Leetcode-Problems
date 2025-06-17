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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comparator = [](const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comparator)> pq;
        for(ListNode* node: lists) {
            if(node) pq.push(node);
        }
        ListNode* result = new ListNode;
        ListNode* temp = result;
        while(!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();
            temp->next = smallest;
            temp = temp->next;
            if(smallest->next) {
                pq.push(smallest->next);
            }
        }

        return result->next;
    }
};
