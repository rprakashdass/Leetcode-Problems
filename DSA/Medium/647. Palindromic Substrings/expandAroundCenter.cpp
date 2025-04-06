class Solution {
    inline int palindrome(string s, int left, int right, int count = 0){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--, right++, count++;
        }
        return count;
    }
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0;i < s.size();i++){
            count += palindrome(s, i, i);
            count += palindrome(s, i, i+1);
        }
        return count;
    }
};
