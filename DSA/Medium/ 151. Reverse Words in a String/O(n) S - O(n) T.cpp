class Solution {
public:
    string reverseWords(string s) {
        istringstream stream(s);
        string word, res;
        while(stream >> word){
            if(!res.empty()) word +=" ";
            res = word + res;
        }
        return res;
    }
};
