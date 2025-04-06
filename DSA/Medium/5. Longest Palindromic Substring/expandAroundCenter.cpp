class Solution {

string expandAroundCenter(string s, int left, int right){
    while(left >= 0 && right < s.size() && s[left] == s[right]){
        left--, right++;
    }
    return s.substr(left+1, right-left-1);
}

public:
    string longestPalindrome(string s) {
        string longest = "";
        for(int i = 0;i < s.size();i++){
            string oddLenPalindrome = expandAroundCenter(s, i, i);
            string evenLenPalindrome = expandAroundCenter(s, i, i+1);
            if(oddLenPalindrome.size() > longest.size()) longest = oddLenPalindrome;
            if(evenLenPalindrome.size() > longest.size()) longest = evenLenPalindrome;
        }
        return longest;
    }
};
