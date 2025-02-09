class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sptr = 0, tptr = 0, cnt = 0;
        for(;tptr < t.size();tptr++){
            if(sptr > s.size()) break;
            if(s[sptr] == t[tptr]){
                cnt++;
                sptr++;
            }
        }
        return cnt == s.size();
    }
};
