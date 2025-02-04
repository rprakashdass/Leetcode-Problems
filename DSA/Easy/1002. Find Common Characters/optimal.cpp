class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int commonCount[26] = {0};
        for(char a: words[0]) commonCount[a - 'a']++;
        for(size_t i  = 1; i < words.size(); i++){
            int currentCount[26] = {0};
            for(char a: words[i]) currentCount[a - 'a']++;
            for(int j = 0;j < 26;j++){
                commonCount[j]  = min(commonCount[j], currentCount[j]);
            }
        }
        vector<string> result; 
        for(int i = 0; i <  26;i++){
            char ch = i + 'a';
            int count = commonCount[i];
            for(int j = 0;j < count;j++){
                result.push_back(string( 1, ch ));
            }
        }
        return result;
    }
};
