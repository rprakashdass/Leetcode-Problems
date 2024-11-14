class Solution {
public:
    string reverseWords(string s) {
        string res, word;
        for(auto a: s){
            if(a == ' '){
                if(!res.empty()) word = " " + word;
                res += word;
                word = "";
            }else{
                word = a+word;            
            }
       }
       if(res.empty()) return word;
       else res += " " + word;
       return res;
    }
};
