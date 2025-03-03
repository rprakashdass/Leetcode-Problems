class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> lesser, equal, greater, ans;
        for(int i = 0;i < n;i++){
            if(nums[i] < pivot){
                lesser.push_back(nums[i]);
            }else if(nums[i] == pivot){
                equal.push_back(nums[i]);
            } else{
                greater.push_back(nums[i]);
            }
        }
        for(int num: lesser) ans.push_back(num);
        for(int num: equal) ans.push_back(num);
        for(int num: greater) ans.push_back(num);
        return ans;
    }
};
