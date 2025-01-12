class Solution {
private:
    int recur(string& text1, string& text2, vector<vector<int>>& memo, int m, int n){
        if(m == 0 || n == 0) return 0;
        if(memo[m][n] != -1) return memo[m][n];

        if(text1[m-1] == text2[n-1]){
            return memo[m][n] =  1 + recur(text1, text2, memo, m-1, n-1);
        }

        int excludeText1 = recur(text1, text2, memo, m, n-1);
        int excludeText2 = recur(text1, text2, memo, m-1, n);

        return memo[m][n] = max(excludeText1, excludeText2);

    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
        return recur(text1, text2, memo, m, n);
         
    }
};
