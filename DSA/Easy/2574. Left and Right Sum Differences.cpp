class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        for(int i = n-2;i >= 0;i--){
            result[i] = result[i+1] + nums[i+1];
        }
        int leftSum = 0;
        for(int i = 0;i < n;i++){
            result[i] = abs(leftSum - result[i]);
            leftSum += nums[i];
        }
        return result;
    }
};
