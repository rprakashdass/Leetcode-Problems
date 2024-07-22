class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalSize = nums1.size() + nums2.size();
        vector<int> resultant(totalSize);
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), resultant.begin());
        int mid =  totalSize/2;
        if(totalSize%2==0){
            double median = (double)(resultant[mid-1] + resultant[mid]) / (double)2;
            return median;
        }else{
            return resultant[mid];
        }
    }
};
