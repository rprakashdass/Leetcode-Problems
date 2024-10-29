class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;

        if(n == 1 && target == nums[0]) return 0;
        while( left <= right ) {
            mid = left + (right - left) / 2; 
            if(nums[mid] == target) {
                return mid;
            } else if (target < nums[mid]){
                right = mid-1;
            } else {
                left = mid+1;
            }                                                                          
        }
        return left;
    }
};
