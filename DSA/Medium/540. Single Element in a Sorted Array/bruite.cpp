class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i = nums.size()-1;
        while(i > 0) {
            if(nums[i] != nums[i-1]) {
                return nums[i];
            }
            i-=2;
        }
        return nums[0];
    }
};
