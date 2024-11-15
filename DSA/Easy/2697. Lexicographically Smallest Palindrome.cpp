class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n-1;
        while(left < right){
            if(s[left] != s[right])
                s[left] = s[right] = min(s[right], s[left]);
            left++;
            right--;
        }
        return s;
    }
};
