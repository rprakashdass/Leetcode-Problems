class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0, count = 0;
        int left = 0, n = nums.size();
        while(left < n){
            if(nums[left] == 0)  {
                left++; continue;
            }
            if(nums[left] > 0) pos++;
            else neg++;
            count = max(pos, neg);
            left++;
        }
        return count;
    }
};
