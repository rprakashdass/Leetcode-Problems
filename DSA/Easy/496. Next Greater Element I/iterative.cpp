// Time complexity - O(n * m)
// Space complexity - O(1)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        for(int i = 0;i < n;i++){
            auto it = find(nums2.begin(), nums2.end(), nums1[i]);
            if(it != nums2.end()){
                bool found = false;
                for(auto ind = it+1;ind != nums2.end();ind++){
                    if(*ind > nums1[i]){
                        nums1[i] = *ind;
                        found = true;
                        break;
                    }
                }
                if(!found) nums1[i] = -1;
            } else {
                nums1[i] = -1;
            }
        }
        return nums1;
    }
};
