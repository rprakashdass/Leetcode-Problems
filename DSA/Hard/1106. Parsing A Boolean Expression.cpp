class Solution {
public:
    bool parseBoolExpr(string exp) {
        stack<char> expStack;

        for(char s: exp) {
            if ( s != ')' && s != ',' ) expStack.push(s);
            else if (s == ')') {

                vector<bool> subExp;

                while ( expStack.top() != '(' && !expStack.empty() ) {
                    subExp.push_back(expStack.top() == 't' ? true : false);
                    expStack.pop();
                }

                expStack.pop();

                if ( !expStack.empty() ) {
                    char evaluator = expStack.top();
                    bool ans = subExp[0];

                    if( evaluator == '&' ) {
                        for ( bool exp: subExp){
                            ans &= exp;
                        }
                    } else if ( evaluator == '|' ){
                        for ( bool exp: subExp){
                            ans |= exp;
                        }
                    } else if ( evaluator == '!' ){
                        ans = !ans;
                    }

                    expStack.pop();
                    expStack.push(ans == true ? 't' : 'f');
                }
            }
        }

        return expStack.top() == 't' ? true : false;
    }
};
