class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int right = 1;
        int sum = nums[0], maxm = nums[0];
        while(right < nums.size()){
            if(nums[right] <= nums[right-1]){
                sum = nums[right];
            } else{
                sum += nums[right];
            }
            right++;
            maxm = max(maxm, sum);
        }
        return maxm;
    }
};
