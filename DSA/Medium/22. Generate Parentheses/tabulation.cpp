class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<vector<string>>> dp(n+1, vector<vector<string>>(n+1));
        dp[n][n] = {""};
        for(int i = n;i >= 0;i--) {
            for(int j = n;j >= 0;j--) {
                if(i == n && j == n) continue;
                if(i < n) {
                    for(const string& suffix: dp[i+1][j]) {
                        dp[i][j].push_back("(" + suffix);
                    }
                }
                if(j < i) {
                    for(const string& suffix: dp[i][j+1]) {
                        dp[i][j].push_back(")" + suffix);
                    }
                }
            }
        }
        return dp[0][0];
    }
};
