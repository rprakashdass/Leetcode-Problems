class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        int left = 0, right = n-1;
        while(left < right){
            char ch = s[left];
            if(!isalpha(s[left])) left++;
            else if(!isalpha(s[right])) right--;
            else {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};
