// Time complexity - O(n*amount)
// Space complexity - O(n*amount)
class Solution {
private:
    int recur(vector<int>& coins, vector<int>& memo, int amount){
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;
        if(memo[amount] != -1) return memo[amount];
        int minCount = INT_MAX;
        for(size_t i = 0;i < coins.size();i++){
            int res = recur(coins, memo, amount-coins[i]);
            if(res != INT_MAX) minCount = min(minCount, res + 1);
        }
        return memo[amount] = minCount;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>memo(amount+1, -1);
        int res = recur(coins, memo, amount);
        return (res != INT_MAX) ? res : -1;
    }
};
