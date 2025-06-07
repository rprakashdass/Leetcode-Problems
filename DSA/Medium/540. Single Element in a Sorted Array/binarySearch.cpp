class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size()-1, mid = (left + right) / 2;
        while(left < right) {
            if(mid-1 >= 0 && mid+1 < nums.size() && nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) {
                return nums[mid];
            } else if (mid%2 == 0){
                if(mid < nums.size() && nums[mid] == nums[mid+1]) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            } else {
                if(nums[mid] == nums[mid-1]) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
            mid = (left + right) / 2;
        }
        return nums[mid];
    }
};
