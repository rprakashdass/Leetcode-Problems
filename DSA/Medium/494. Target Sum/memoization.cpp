// Time complexity -> O(N*target)
// Space complexity -> O(N*target)

class Solution {
private:
    int recur(vector<int>& nums, vector<vector<int>>& memo, int target, int index){
        if(index == nums.size()){
           return (target == 0) ? 1: 0;
        }
        if (target < -1000 || target > 1000) return 0;
        if(memo[index][target+1000] != -1) return memo[index][target+1000];
        int case1 = recur(nums, memo, target + nums[index], index+1);
        int case2 = recur(nums, memo, target - nums[index], index+1);
        return memo[index][target+1000] = case1 + case2;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(2001, -1)); 
        return recur(nums, memo, target, 0);
    }
};
