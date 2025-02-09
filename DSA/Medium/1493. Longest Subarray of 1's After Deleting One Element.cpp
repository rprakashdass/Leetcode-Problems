class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), zeros = 0, left = 0;
        int count = 0;
        for(int right = 0;right < n;right++){
            if(nums[right] == 0) zeros++;
            if(zeros > 1){
                if(nums[left] == 0) zeros--;
                left++;
            }
            count = max(count, right-left);
        }
        return count;
    }
};
