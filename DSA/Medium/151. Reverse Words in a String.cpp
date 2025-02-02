class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string w = "";
        string result = "";
        for(int i = 0;i < n;i++){
            if(s[i] == ' '){
                if(w.size() >= 1)  result = w + " " + result;
                w = "";
            } else{
                w += s[i];
            }
        }
        if(w.size() >= 1) result = w + " " + result;
        return result.substr(0, result.size()-1);
    }
};
