class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stq;
        for(char ch: s){
            if(stq.empty() || stq.top() != ch) stq.push(ch);
            else {
                while(!stq.empty() && ch == stq.top()){
                    stq.pop();
                }
            }
        }
        string result = "";
        while(!stq.empty()){
            result = stq.top() + result;
            stq.pop();
        }
        return result;
    }
};
