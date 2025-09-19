class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            if(nums[left] == target || nums[right] == target) return true;
            left++, right--;
        }
        return false;
    }
};


/*

[4, 5, [6, 7, 0, 1], 2], 0

bruit force => looping from  0 to n-1 th indices
optimized => binary search

*/
