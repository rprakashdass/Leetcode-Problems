class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> counter;
        for(const string& str: strs){
            vector<int> count(26, 0);
            for(const char& ch: str) count[ch-'a']++;
            string key = "";
            // delimeter # helps to seperate count of every chars
            for(int i = 0;i < 26;i++) key += to_string(count[i]) + "#";
            counter[key].push_back(str);
        }
        vector<vector<string>> result;
        for(auto [_, str]: counter) {
            result.push_back(str);
        }
        return result;
    }
};
