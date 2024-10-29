class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int left = 0;
        int right = nums.size()-1;
        int mid = 0;

        vector<int> result(2, -1);

        if(!n) return result;

        while( left <= right ) {
            mid = left + (right - left) / 2; 
            if (target <= nums[mid]){
                right = mid-1;
            } else {
                left = mid+1;
            }
        }

        cout << left;
        if(left >= n) return result;
        if(nums[left] != target) return result;
        
        result[0] = left;

        right = n-1;
        while( left <= right ) {
            mid = left + (right - left) / 2; 
            if (target < nums[mid]){
                right = mid-1;
            } else {
                left = mid+1;
            }
        }

        result[1] = right;
        return result;

    }
};
