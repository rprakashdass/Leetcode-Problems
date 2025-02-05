class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;
        auto isSwap = [](string s, string s2, const int i, const int j){
            swap(s[i], s[j]);
            if(s == s2) return true;
            return false;
        };
        int n = s1.size();
        for(int i = 0;i < n;i++){
            int lft = i;
            for(int j = i+1;j < n;j++){  
                int rgt = j;       
                if(isSwap(s1, s2, lft, rgt)) return true;
            }
        }
        return false;
    }
};
