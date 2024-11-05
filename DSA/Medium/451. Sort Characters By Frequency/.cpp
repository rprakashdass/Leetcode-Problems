// TC -> O(2N) 

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> hm;

        for(auto a: s){
            hm[a]++;
        }

        vector<pair<char, int>> freq_vec(hm.begin(), hm.end());

        sort(freq_vec.begin(), freq_vec.end(), [](const pair<char, int>& a, const pair<char, int>& b){
            if(a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        });

        string res;
        for(auto it: freq_vec){
            for(int i = 0;i < it.second;i++)
                res += it.first;
        }

        return res;

    }
};
