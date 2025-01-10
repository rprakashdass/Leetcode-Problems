class Solution {
private:
    int recur(vector<int>& coins, vector<vector<int>>& memo, int amount, int coin) {
        if (amount == 0) return 1;

        if (amount < 0) return 0;

        if (memo[amount][coin] != -1) return memo[amount][coin];

        int count = 0;
        for (size_t i = coin; i < coins.size(); i++) {
            count += recur(coins, memo, amount - coins[i], i);
        }

        return memo[amount][coin] = count;
    }

public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(amount + 1, vector<int>(coins.size(), -1));
        return recur(coins, memo, amount, 0);
    }
};
