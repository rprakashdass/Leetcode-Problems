class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int left  = 0, right = 0;
        vector<int> result;
        priority_queue<pair<int, int>> pq;
        while(right < n){
            pq.push({nums[right], right});
            if(right - left + 1 == k){
                while(!pq.empty() && pq.top().second < left) pq.pop();
                result.push_back(pq.top().first);
                left++;
            }
            right++;
        }
        return result;
    }
};
