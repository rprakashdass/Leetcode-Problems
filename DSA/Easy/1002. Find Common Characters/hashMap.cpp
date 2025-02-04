class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> commonCount;
        for(char a: words[0]) commonCount[a]++;
        for(size_t i  = 1; i < words.size(); i++){
            unordered_map<char, int> currentCount;
            for(char a: words[i]) currentCount[a]++;
            for(auto& it: commonCount){
                char key = it.first;
                commonCount[key]  = min(commonCount[key], currentCount[key]);
            }
        }
        vector<string> result; 
        for(auto& it: commonCount){
            for(int i = 0;i < it.second;i++){
                result.push_back(string( 1, it.first ));
            }
        }
        return result;
    }
};
