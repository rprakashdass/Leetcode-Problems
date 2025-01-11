class Solution {
private:
    int recur(vector<int>& nums, vector<vector<int>>& memo, int prev, int ind){
        if(ind == nums.size()) return 0;
        if(memo[prev+1][ind] != -1) return memo[prev+1][ind];
        int include = 0;
        if(prev == -1 || nums[prev] < nums[ind]){
            include = 1 + recur(nums, memo, ind, ind+1);
        }
        int exclude = recur(nums, memo, prev, ind+1);
        return memo[prev+1][ind] = max(include, exclude);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n+1, vector<int>(n, -1));
        return recur(nums, memo, -1, 0);
    }
};
