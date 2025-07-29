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
