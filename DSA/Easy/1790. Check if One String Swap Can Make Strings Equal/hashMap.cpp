class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;
        auto isSwap = [](string s, string s2, const int i, const int j){
            swap(s[i], s[j]);
            if(s == s2) return true;
            return false;
        };
        int n = s2.size();
        unordered_map<char, vector<int>> counter;
        for(int i = 0;i < s2.size();i++) counter[s1[i]].push_back(i);
        for(int i = 0;i < s1.size();i++){
            char key = s2[i];
            if(counter.find(key) != counter.end()){
                for(int pair: counter[key]){
                    if(isSwap(s1, s2, i, pair)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
