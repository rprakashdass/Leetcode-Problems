class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), mx = 1;
        if(n <= 1) return n;
        set<int> s(nums.begin(), nums.end());
        nums.assign(s.begin(), s.end());
        int i = 0;
        for (int j = 1; j < n; j++) {
            if (nums[j] == nums[j - 1]) i = j;
            else if(nums[j] != nums[j-1]+1) i = j;
            mx = max(mx, j - i + 1);
        }
        return mx;
    }
};
