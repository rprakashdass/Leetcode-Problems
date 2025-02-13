class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int i = 0;i < n;i++){
            pq.push(nums[i]);
        }
        while(pq.size() > 1 && pq.top() < k){
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            pq.push((x * 2) + y);
            cnt++;
        }
        return cnt;
    }
};
