class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(int num: arr){
            freq[num]++;
        }
        bool seen[1001] = {false};
        for(auto [key, value]: freq){
            if(seen[value]) return false;
            seen[value] = true;
        }
        return true;
    }
};
