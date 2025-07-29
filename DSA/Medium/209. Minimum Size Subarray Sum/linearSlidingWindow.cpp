class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0, sum = 0;
        int minLen = INT_MAX;
        while(right < n) {
            sum += nums[right];
            while(sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return (minLen != INT_MAX) ? minLen : 0;
    }
};
