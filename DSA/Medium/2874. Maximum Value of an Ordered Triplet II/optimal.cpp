class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxEle = 0, maxDiff = 0, maxValue = 0;
        for(long long num: nums){
            maxValue = max(maxValue, maxDiff * num);
            maxDiff = max(maxDiff, maxEle - num);
            maxEle = max(maxEle, num);
        }
        return maxValue;
    }
};
