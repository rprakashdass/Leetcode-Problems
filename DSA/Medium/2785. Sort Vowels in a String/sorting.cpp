class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        auto isVowel = [](char ch){
            ch = tolower(ch);
            return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
        };
        for(char ch: s){
            if(isVowel(ch)) vowels.push_back(ch); 
        }
        sort(vowels.begin(), vowels.end()); // at most K log K complexity, always O(1)
        int vowelIndex = 0;
        for(int i = 0;i < s.size();i++){
            if(isVowel(s[i])){
                s[i] = vowels[vowelIndex++];
            }
        }
        return s;
    }
};
