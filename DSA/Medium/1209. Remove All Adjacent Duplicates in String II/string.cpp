class Solution {
public:
    string removeDuplicates(string s, int k) {
        string result = "";
        for(char ch: s){
            result.push_back(ch);
            if(!result.empty() && result[result.size()-1] == ch){
                int i = result.size()-1, temp = k;
                while(i >= 0 && temp >= 0 && result[i] == ch){
                    temp--;
                    i--;
                }
                if(temp == 0) {
                    temp = k;
                    while(temp-- > 0){
                        result.pop_back();
                    }
                }
            }
        }
        return result;
    }
};
