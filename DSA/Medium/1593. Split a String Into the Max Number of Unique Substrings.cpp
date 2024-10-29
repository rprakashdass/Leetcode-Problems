class Solution {
private:
    int backtrack(string s, int ind, unordered_set<string>& str) {
        if(ind == s.size()) return 0;

        int maxm = 0;

        for(int end = ind+1;end <= s.size();end++) {
            string subStr = s.substr(ind, end-ind);
            if(str.find(subStr) == str.end()) {
                str.insert(subStr);
                maxm = max(maxm, 1 + backtrack(s, end, str));
                str.erase(subStr);
            }
        }
        return maxm;
    }
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> str;
        return backtrack(s, 0, str);
    }
};
