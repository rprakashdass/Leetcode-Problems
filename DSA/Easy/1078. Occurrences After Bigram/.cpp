class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        
        vector<string> words;
        vector<string> res;
        string wrd;

        istringstream stream(text);
        while(stream >> wrd){
            words.push_back(wrd);
        }

        for(int i = 1;i < words.size() - 1;i++){
            if(words[i-1] == first && words[i] == second){
                res.push_back(words[i+1]);
            }
        }

        return res;
    }
};
