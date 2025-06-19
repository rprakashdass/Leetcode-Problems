class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > minHeap;

        for(int row = 0;row < matrix.size();row++) {
            minHeap.push({matrix[row][0], {row, 0}});
        }

        int result;
        while(k--) {
            pair<int, pair<int, int>> top = minHeap.top();
            minHeap.pop();
            result = top.first;
            int row = top.second.first;
            int col = top.second.second;
            if(col + 1 < matrix[row].size()) {
                minHeap.push({matrix[row][col + 1], {row, col + 1}});
            }
        }
        return result;
    }
};
