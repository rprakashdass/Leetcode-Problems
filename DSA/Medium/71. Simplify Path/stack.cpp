class Solution {
public:
    string simplifyPath(string path) {
        string tok;
        stringstream iss(path);
        stack<string> stq;
        while(getline(iss, tok, '/')){
            if(tok == "." || tok == "") continue;
            if(tok == ".."){
                if(!stq.empty()){
                    stq.pop();
                } 
            } else {
                stq.push(tok);
            }
        }
        string result = "";
        while(!stq.empty()){
            result = "/" + stq.top() + result;
            stq.pop();
        }
        return result.empty() ? "/"  : result;
    }
};
