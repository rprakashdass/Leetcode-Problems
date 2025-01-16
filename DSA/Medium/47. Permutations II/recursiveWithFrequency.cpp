class Solution {
private:
    void getPermutations(vector<int>& nums, vector<vector<int>>& result, vector<int>& ar, vector<bool>& visited){
        if(ar.size() == nums.size()){
            result.push_back(ar);
            return;
        }
        for(int i = 0;i < nums.size();i++){
            if(visited[i]) continue;
            if(i > 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;
            visited[i]=true;
            ar.push_back(nums[i]);
            getPermutations(nums, result, ar, visited);
            visited[i]=false;
            ar.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> visited(nums.size(), false);
        vector<int> ar;
        sort(nums.begin(), nums.end());
        getPermutations(nums, result, ar, visited);
        return result;
    }
};
