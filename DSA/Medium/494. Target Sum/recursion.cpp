// Time Complexity -> O(2*n)
// Space Complexity -> O(n)
  
class Solution {
private:
    int recur(vector<int>& nums, int target, int index){
        if(index == nums.size()){
           return (target == 0) ? 1: 0;
        }
        int case1 = recur(nums, target + nums[index], index+1);
        int case2 = recur(nums, target - nums[index], index+1);
        return case1 + case2;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return recur(nums, target, 0);
    }
};
