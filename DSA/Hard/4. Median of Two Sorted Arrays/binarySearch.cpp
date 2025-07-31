class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int symmetrySize = (n + m + 1) / 2;
        int left  = 0, right = n;
        if(n > m) return findMedianSortedArrays(nums2, nums1);
        while(left <= right) {
            int mid1 = (left + right) >> 1;
            int mid2 = symmetrySize - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if(mid1 < n) r1 = nums1[mid1];
            if(mid2 < m) r2 = nums2[mid2];
            if(mid1-1 >= 0) l1 = nums1[mid1-1];
            if(mid2-1 >= 0) l2 = nums2[mid2-1];
            if(l1 <= r2 && l2 <= r1) {
                if((n + m) % 2 != 0) return max(l1, l2);
                else {
                    return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
                }
            } else if(l1 > r2) {
                right = mid1 - 1;
            } else {
                left = mid1 + 1;
            }
        }
        return 0;
    }
};
