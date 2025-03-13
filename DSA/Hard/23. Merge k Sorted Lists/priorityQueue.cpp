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
private:
struct Comparator{
    bool operator()(const ListNode& a, const ListNode& b){
        return a.val > b.val;
    }
};

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        priority_queue<ListNode, vector<ListNode>, Comparator> pq;
        for(ListNode* list : lists){
            while(list){
                pq.push(*list);
                list = list->next;
            }
        }
        ListNode* result = new ListNode;
        ListNode* temp = result;
        while(!pq.empty()){
            temp->next = new ListNode(pq.top());
            pq.pop();
            temp = temp->next;
        }
        temp->next = nullptr;
        return result->next;
    }
};
