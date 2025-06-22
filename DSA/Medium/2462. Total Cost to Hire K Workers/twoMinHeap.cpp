class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        int left = 0, right = n-1;
        priority_queue<int, vector<int>, greater<int>> leftHeap, rightHeap;

        while(left < n && leftHeap.size() < candidates) {
            leftHeap.push(costs[left++]);
        }

        while(left <= right && rightHeap.size() < candidates) {
            rightHeap.push(costs[right--]);
        }

        long long totalCost = 0;
        while(k--) {
            int leftMin = leftHeap.empty() ? INT_MAX : leftHeap.top();
            int rightMin = rightHeap.empty() ? INT_MAX : rightHeap.top();

            if(leftMin <= rightMin){
                totalCost += leftMin;
                leftHeap.pop();
                if(left <= right) {
                    leftHeap.push(costs[left++]);
                }
            } else {
                totalCost += rightMin;
                rightHeap.pop();
                if(left <= right) {
                    rightHeap.push(costs[right--]);
                }
            }
        }
        return totalCost;
    }
};
