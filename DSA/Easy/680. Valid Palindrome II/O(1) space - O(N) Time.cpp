class Solution {
private:
    bool is_palindrome(string s, int left, int right){
        while(left < right){
            if(s[left] != s[right])
                return 0;
            left++;
            right--;
        }
        return 1;
    }
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n-1;
        while(left < right){
            if(s[left] != s[right])
                return is_palindrome(s, left+1, right) || is_palindrome(s, left, right-1);
                left++;
                right--;
        }
        return 1;
    }
};
