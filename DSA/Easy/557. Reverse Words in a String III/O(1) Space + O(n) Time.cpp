class Solution {
public:
    string reverseWords(string s) {
        int right = 0;
        int left = 0;
        int n = s.size();
        while(right <= n){
            if(right == n || s[right] == ' '){
                reverse(s.begin() + left, s.begin() + right);
                left = right+1;
            }
            right++;
       }
       return s;
    }
};
