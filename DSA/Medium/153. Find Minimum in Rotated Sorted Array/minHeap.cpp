class Solution {
public:
    int findMin(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int num: nums) {
            minHeap.push(num);
        }
        return minHeap.top();
    }
};
