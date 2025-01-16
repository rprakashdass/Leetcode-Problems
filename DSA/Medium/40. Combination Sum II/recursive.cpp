class Solution {
private:
    void recur(vector<int>& nums, vector<vector<int>>& result, vector<int>& ar, int ind, int target) {
        if (target < 0) return;
        if (target == 0) {
            result.push_back(ar);
            return;
        }
        for(int i = ind;i < nums.size();i++){
            if(i > ind && nums[i] == nums[i-1]) continue;
            if (nums[i] > target) break;
            ar.push_back(nums[i]);
            recur(nums, result, ar, i+1, target - nums[i]);
            ar.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> ar;
        recur(candidates, result, ar, 0, target);
        return result;
    }
};
