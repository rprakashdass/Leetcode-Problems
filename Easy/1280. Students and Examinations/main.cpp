class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<string> result;
        unordered_map<int, string> mp;

        for(int i = 0;i < n;i++){
            mp[heights[i]] = names[i];
        }

        sort(heights.begin(), heights.end(), greater<int>());

        for(int i = 0;i < n;i++){
            result.push_back(mp[heights[i]]);
        }

        return result;

    }
};
