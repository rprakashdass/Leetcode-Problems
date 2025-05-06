class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stq;
        for(char ch: s){
            if(!stq.empty() && stq.top() == ch) stq.pop();
            else stq.push(ch);
        }
        string result(stq.size(), ' ');
        for(int i = stq.size()-1; i >= 0;--i){
            result[i] = stq.top();
            stq.pop();
        }
        return result;
    }
};
