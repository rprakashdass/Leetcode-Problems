class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        int n = nums.size();
        int lastAdded = nums[0];
        int result = nums[0];
        for(int i = 1;i < n;i++) {
            lastAdded = max(nums[i], lastAdded + nums[i]);
            result = max(result, lastAdded);
        }
        return result;
    }
};
