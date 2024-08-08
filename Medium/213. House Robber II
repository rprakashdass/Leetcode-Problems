class Solution {
private:
    int func(int s, int e, vector<int>& nums) {
        if (e - s == 0) return nums[s];
        if (e - s == 1) return max(nums[s], nums[s + 1]);
        int p = nums[s];
        int ip = max(nums[s], nums[s + 1]);
        int cur = 0;
        for (int i = s + 2; i <= e; i++) {
            cur = max(p + nums[i], ip);
            p = ip;
            ip = cur;
        }
        return ip;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        return max(func(0, n - 2, nums), func(1, n - 1, nums));
    }
};
