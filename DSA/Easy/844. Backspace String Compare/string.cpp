class Solution {
public:
    string removeBackspace(string s){
        string temp = "";
        for(char ch: s){
            if(ch == '#'){
                if(!temp.empty()) temp.pop_back();
            } else {
                temp.push_back(ch);
            }
        }
        return temp;
    }
    bool backspaceCompare(string s, string t) {
        return removeBackspace(s) == removeBackspace(t);
    }
};
