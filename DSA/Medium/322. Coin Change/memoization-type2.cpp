// Time complexity - O(n*amount)
// Space complexity - O(n*amount)
class Solution {
private:
    int recur(vector<int>& coins, vector<vector<int>>& memo, int index, int target){
        if(target < 0 || index < 0) return INT_MAX;
        if(target == 0) return 0;
        if(memo[index][target] != -1) return memo[index][target];
        int take = recur(coins, memo, index, target-coins[index]);
        int notTake = recur(coins, memo, index-1, target);
        if(take != INT_MAX) take += 1;
        return memo[index][target] = min(take, notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> memo(n, vector<int>(amount+1, -1));
        int res = recur(coins, memo, n-1, amount);
        return (res != INT_MAX) ? res : -1;
    }
};
