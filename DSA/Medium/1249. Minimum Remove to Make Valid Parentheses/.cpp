// TC -> O(2N)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string result;
        int n = s.size();

        int cnt = 0;
        for(int i = 0;i < n;i++){
            if(s[i] == '('){
                result.push_back(s[i]);
                cnt++;
            } else if (s[i] == ')' && cnt > 0){
                result.push_back(s[i]);
                cnt--;
            } else if (s[i] != ')'){
                result.push_back(s[i]);
            }
        }

        int i = result.size()-1;
        while( i >= 0 && cnt > 0 ){
            if(result[i] == '('){
                result.erase(i, 1);
                cnt--;
            }
            i--;
        }

        return result;
    }
};
