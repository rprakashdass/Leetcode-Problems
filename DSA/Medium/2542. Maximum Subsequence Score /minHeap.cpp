class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> pairs;
        for(int i = 0;i < nums1.size();i++) {
            pairs.push_back({nums2[i], nums1[i]});
        }
        sort(pairs.rbegin(), pairs.rend());

        long long result = 0, sum = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto &[num2, num1]: pairs) {
            minHeap.push(num1);
            sum += num1;

            if(minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            if(minHeap.size() == k) {
                result = max(result, sum * (long long) num2);
            }
        }
        return result;
    }
};
