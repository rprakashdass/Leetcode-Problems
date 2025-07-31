class Solution {
    unordered_map<int , unordered_map<int, vector<string>>> memo;
public:
    vector<string> generate(int open, int close, int& n){
        if(open == n && close == n){
            return {""};
        }
        if(memo.count(open) && memo[open].count(close)) {
            return memo[open][close];
        }
        vector<string> result;
        if(open < n){
            vector<string> suffixes = generate(open+1, close, n);
            for(const string& suffix: suffixes) {
                result.push_back("("+suffix);
            }
        }
        if(close < open){
            vector<string> suffixes = generate(open, close+1, n);
            for(const string& suffix: suffixes) {
                result.push_back(")"+suffix);
            }
        }
        return memo[open][close] = result;
    }
    vector<string> generateParenthesis(int n) {
        return generate(0, 0, n);
    }
};
