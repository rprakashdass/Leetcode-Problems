class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, sum = 0;
        double maxAvg = INT_MIN;
        for(int right = 0;right < n;right++){
            sum += nums[right];
            if(right-left+1 == k){
                maxAvg = max(maxAvg, (double)sum/k);
                sum -= nums[left];
                left++;
            }
        }
        return maxAvg;
    }
};
