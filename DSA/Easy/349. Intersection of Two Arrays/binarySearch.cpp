class Solution {
public:
    bool search(vector<int> nums, int target){
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target) return true;
            else if (target > nums[mid]){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for(int i = 1;i < nums1.size();i++){
            if(nums1[i-1] == nums1[i]) nums1[i-1] = -1;
        }
        for(int i = 0;i < nums1.size();i++){
            if(search(nums2, nums1[i])) result.push_back(nums1[i]);
        }
        return result;
    }
};
