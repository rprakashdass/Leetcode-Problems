class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> maxHeap;
        for(vector<int> row: matrix) {
            if(maxHeap.size() > k && row[0] > maxHeap.top()) break;
            for(int num: row) {
                if(maxHeap.size() < k) {
                    maxHeap.push(num);
                }
                else if(num < maxHeap.top()) {
                    maxHeap.pop();
                    maxHeap.push(num);
                } else {
                    break;
                }
            }
        }
        return maxHeap.top();
    }
};
