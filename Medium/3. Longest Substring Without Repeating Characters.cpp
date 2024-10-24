// Brute force O(N*N)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxCount = 0;
        for(int i = 0;i < n;i++){
            map<int, int> mp;
            int count = 0;
            for(int j = i;j < n;j++){
                if(mp.find(s[j]) != mp.end()) break;
                mp[s[j]]++;
                count++;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};

// 
