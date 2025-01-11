class Solution {
private:
    int recur(auto& pairs, auto& memo, int prev, int cur){
        if(cur == pairs.size()) return 0;
        if(memo[prev+1][cur] != -1) return memo[prev+1][cur];
        int include = 0;
        if(prev == -1 || pairs[prev][1] < pairs[cur][0]){
            include = 1 + recur(pairs, memo, cur, cur+1);
        }
        int exclude = recur(pairs, memo, prev, cur+1);
        return memo[prev+1][cur] = max(include, exclude);
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>&b){
            return a[1] < b[1];
        });
        vector<vector<int>> memo(n+1, vector<int>(n, -1));
        return recur(pairs, memo, -1, 0);
    }
};
