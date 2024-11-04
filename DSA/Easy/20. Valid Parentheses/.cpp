class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(auto chr: s ){
            if (chr == ')') {
                if (!stack.empty() && stack.top() == '(') {
                    stack.pop();
                } else {
                    return false;
                }
            } 
            else if (chr == ']') {
                if (!stack.empty() && stack.top() == '[') {
                    stack.pop();
                } else {
                    return false;
                }
            }
            else if (chr == '}') {
                if (!stack.empty() && stack.top() == '{') {
                    stack.pop();
                } else {
                    return false;
                }
            }
            else {
                stack.push(chr);
            }
        }
        return stack.empty();
    }
};
