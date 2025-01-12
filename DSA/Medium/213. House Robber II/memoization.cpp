class Solution {
private:
    int recur(int i, vector<int>& ar, vector<int>& dp) {
        if(i == 0) return ar[0];
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        
        int take = ar[i] + recur(i-2, ar, dp);
        int doNotTake = recur(i-1, ar, dp);

        return dp[i] = max(take, doNotTake);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        vector<int> withFirst(nums.begin(), nums.end()-1);
        vector<int> withLast(nums.begin()+1, nums.end());

        vector<int> dp(n, -1);
        int first = recur(n-2, withFirst, dp);

        dp.assign(n, -1);
        int last = recur(n-2, withLast, dp);

        return max(first, last);
    }
};
