class Solution {
public:
    bool isAnagram(string s, string t) {
        int counter[26] = {0};
        for(char c: s) counter[c - 'a']++;
        for(char c: t)  counter[c - 'a']--;
        for(int i = 0;i < 26;i++){
            if(counter[i] != 0) return false;
        }
        return true;
    }
};      
