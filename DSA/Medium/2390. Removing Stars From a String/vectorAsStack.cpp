class Solution {
public:
    string removeStars(string s) {
        string result = "";
        for(char ch: s){
            if(!result.empty() && ch == '*'){
                result.pop_back();
            } else {
                result.push_back(ch);
            }
        }
        return result;
    }
};
