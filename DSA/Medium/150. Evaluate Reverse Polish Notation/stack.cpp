class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stq;
        for(string token: tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int b = stq.top(), stq.pop();
                int a = stq.top(), stq.pop();
                if(token == "+"){
                    stq.push(a + b);
                } else if(token == "-"){
                    stq.push(a-b);
                } else if(token == "*"){
                    stq.push(a*b);
                } else {
                    stq.push(a/b);
                }
            } else {
                stq.push(stoi(token));
            }
        }
        return stq.top();
    }
};
