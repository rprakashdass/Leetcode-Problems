class Solution {
public:
    void generate(vector<string>& result, string paranthesis, int i, int openCount, int closeCount, int& n){
        if(i == n+n){
            result.push_back(paranthesis);
        }
        if(openCount < n){
            generate(result, paranthesis + "(", i+1, openCount+1, closeCount, n);
        }
        // this condition ensures valid brackets
        if(closeCount < openCount){
            generate(result, paranthesis + ")", i+1, openCount, closeCount+1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(result, "",0, 0, 0, n);
        return result;
    }
};
