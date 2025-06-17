class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp;
        for(int num: arr) {
            mp[num] = 0;
        }
        int i = 0;
        for(auto [num, _] : mp) {
            mp[num] = ++i;
        }
        for(int i = 0;i < arr.size();i++) {
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};
