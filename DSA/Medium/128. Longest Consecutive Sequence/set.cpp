class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;
        int maxLen = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for(int num: s) {
            // num-1 helps to whethers its not the starting number of consecutive elements
            if(s.find(num-1) == s.end()) {
                int len = 1;
                while(s.find(num+len) != s.end()) {
                    len++;
                }
                maxLen = max(len, maxLen);
            }
        }
        return maxLen;
    }
};
