class Solution {
private:
    void recur(int i, vector<vector<int>>& ans, vector<int>& nums, int n)
    {
        if(i == n){
            ans.push_back(nums);
            return;
        }
        for(int ind = i;ind < n;ind++){
            swap(nums[ind], nums[i]);
            recur(i+1, ans, nums, n);
            swap(nums[ind], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recur(0, ans, nums, nums.size());
        return ans;
    }
};
