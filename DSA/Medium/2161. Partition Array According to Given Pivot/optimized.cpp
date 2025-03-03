class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int equalCount = 0, ansPtr = 0;
        for(int i = 0;i < n;i++){
            if(nums[i] < pivot){
                ans[ansPtr++] = nums[i];
            }else if(nums[i] == pivot){
                equalCount++;
            }
        }
        for(int i = 0;i < equalCount;i++){
            ans[ansPtr++] = pivot;
        }
        for(int i = 0;i < n;i++){
            if(nums[i] > pivot){
                ans[ansPtr++] = nums[i];
            }
        }
        return ans;
    }
};
