class Solution {
public:
    int recur(vector<vector<int>>& memo, int i, int j, int m, int n) {
        if(i == 0 || j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        return memo[i][j] = recur(memo, i-1, j, m, n) + recur(memo, i, j-1, m, n);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int> (n, -1));
        return recur(memo, m-1, n-1, m, n);
    }
};
