class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp;
        for(auto a: s){
            mp[a]++;
        }
        for(auto a: t){
            if(!mp[a]) return a;
            mp[a]--;
        }
        return '\0';
    }
};
