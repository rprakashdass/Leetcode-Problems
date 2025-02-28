class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        vector<int> frequency(26, 0);
        for(int i = 0;i < n;i++) frequency[s[i] - 'a']++;
        for(int i = 0;i < n;i++){
            if(frequency[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};
