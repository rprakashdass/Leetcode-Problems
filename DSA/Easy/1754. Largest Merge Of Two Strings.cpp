class Solution {
public:
    string largestMerge(string word1, string word2) {
        string res;
        int i = 0, j = 0, n = word1.size(), m = word2.size();
        while(i < n && j < m){
            if(word1.substr(i) > word2.substr(j)) res += word1[i++];
            else res += word2[j++];
        }
        while(i < n) res += word1[i++];
        while(j < m) res += word2[j++];
        return res;
    }
};
