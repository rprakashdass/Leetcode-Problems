// Time complexity - O(2^n)
// Space complexity - O(2^n)
class Solution {
void getSubset(vector<vector<int>>& result, vector<int>& ar,  vector<int>& nums, int i){
    if(i == nums.size()){
        result.push_back(ar);
        return;
    }
    getSubset(result, ar, nums, i+1);
    ar.push_back(nums[i]);
    getSubset(result, ar, nums, i+1);
    ar.pop_back();
}
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ar;
        getSubset(result, ar, nums, 0);
        return result;
    }
};
