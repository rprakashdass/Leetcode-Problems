class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int inc = 0, dec = 0, maxm = 0;
        for(int i = 0;i < n;i++){
            inc = 1, dec = 1;
            for(int j = i;j < n-1 && nums[j] > nums[j+1];j++){
                dec++;
            }
            for(int j = i;j < n-1 && nums[j] < nums[j+1];j++){
                inc++;
            }
            maxm = max(maxm, max(inc, dec));
        }
        return maxm;
    }
};
