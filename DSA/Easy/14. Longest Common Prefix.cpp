class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string res = "";
        for(int i = 0;i < strs[0].size();i++){
            int count = 0;
            for(auto str: strs){
                if(str[i] == strs[0][i]) count++;
                else return res;
            }
            if(count == n) res+=strs[0][i];
        }
        return res;
    }
};
