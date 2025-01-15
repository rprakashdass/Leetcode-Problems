class Solution {
private:
    int findFib(int n, vector<int>& memo){
        if(n <= 1) return n;
        if(memo[n] != -1) return memo[n];
        return memo[n] = findFib(n-1, memo) + findFib(n-2, memo);
    }
public:
    int fib(int n) {
        vector<int> memo(n+1, -1);
        return findFib(n, memo);
    }
};
