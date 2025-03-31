class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& g, vector<int>& s) {
        if(s.empty()) return 0;
        int noOfChild = g.size(), noOfCookies = s.size(), matchings = 0;

        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());

        int j = 0;
        for(int i = 0; i < noOfChild;i++){
            if(j < noOfCookies && s[j] >= g[i]){
                matchings++;
                j++;
            }
        }
        return matchings;
    }
};
