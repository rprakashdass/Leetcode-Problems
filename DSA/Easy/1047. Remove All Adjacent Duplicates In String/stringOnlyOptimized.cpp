class Solution {
public:
    string removeDuplicates(string s) {
        string result = "";
        for(char ch: s){
            if(!result.empty() && result[result.size()-1] == ch) result.pop_back();
            else result.push_back(ch);
        }
        return result;
    }
};
