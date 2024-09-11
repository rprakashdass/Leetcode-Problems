class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() < 2) return true;
        
        string cleanedString = "";
        for(int i = 0; i < s.length(); ++i){
            if(isalnum(s[i]) && s[i] != ' ')
                cleanedString += tolower(s[i]);
        }

        int left = 0;
        int right = cleanedString.length() - 1;

        while (left < right) {
            if (cleanedString[left] != cleanedString[right]) {
                return false;
            }
            ++left;
            --right;
        }

        return true;
    }
};
