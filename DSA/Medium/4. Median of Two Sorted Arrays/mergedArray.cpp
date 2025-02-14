class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> merged;
        
        int m = nums1.size();
        int n = nums2.size();

        int i = 0, j = 0;
        while(i < m && j < n){
            int ele;
            if(nums1[i] <= nums2[j]) ele = nums1[i], i++;
            else ele = nums2[j], j++;
            merged.push_back(ele);
        }

        while(i < m) merged.push_back(nums1[i++]);
        while(j < n) merged.push_back(nums2[j++]);

        int totalSize = m + n;
        int mid = totalSize / 2;
        if (totalSize % 2 == 1) {
            return merged[mid];
        } else {
            return (merged[mid - 1] + merged[mid]) / 2.0;
        }

    }
};
