class Solution {
private:
    void recur(vector<vector<int>>& ans, vector<int>& nums, vector<int>& freq, vector<int>& data, int n)
    {
        if(data.size() == n){
            ans.push_back(data);
            return;
        }
        for(int i = 0;i < n;i++){
            if(!freq[i])
            {
                freq[i] = 1;
                data.push_back(nums[i]);
                recur(ans, nums, freq, data, nums.size());
                freq[i] = 0;
                data.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> data;
        vector<int> freq(nums.size(), 0);
        recur(ans, nums, freq, data, nums.size());
        return ans;
    }
};
