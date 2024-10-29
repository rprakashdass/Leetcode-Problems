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

// Sliding window - O(N)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0,r = 0;
        int count = 0, maxCount = 0;
        unordered_map<char, int> hashMap;
        while(r < n){
            if(hashMap.find(s[r]) != hashMap.end()){
                if(hashMap[s[r]] >= l){
                    l = hashMap[s[r]]+1;
                }
            }
            hashMap[s[r]] = r;
            maxCount = max(maxCount,r-l+1);
            r++;
        }
        return maxCount;
    }
};
