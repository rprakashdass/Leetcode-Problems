class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0, sum = 0;
        int n = nums.size(), left = 0, right = 0;
        unordered_map<int, int> counter;
        while(right < n){
            counter[nums[right]]++;
            sum += nums[right];
            if(right-left+1 > k){
                counter[nums[left]]--;
                sum -= nums[left];
                if(counter[nums[left]] == 0) counter.erase(nums[left]);
                left++;
            }
            if(right-left+1 == k && counter.size() == k){
                ans = max(ans, sum);
            }
            right++;
        }
        return ans;
    }
};
