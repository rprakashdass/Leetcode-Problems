class Solution {
    void getSubsetSum(vector<vector<int>>& result, vector<int>& ar, int k, int i, int n){
        if(ar.size() == k){
            if(n == 0){
                result.push_back(ar);
            }
            return;
        }
        if(i > 9 || n < 0) return;
        ar.push_back(i);
        getSubsetSum(result, ar, k, i+1, n-i);
        ar.pop_back();
        getSubsetSum(result, ar, k, i+1, n);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> ar;
        getSubsetSum(result, ar, k, 1, n);
        return result;
    }
};
