class Solution {
public:
    string sortVowels(string s) {
        string t = "";
        map<char, int> mp;
        auto isVowel = [](char ch){
            ch = tolower(ch);
            return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
        };
        for(char ch: s){
            if(isVowel(ch)) mp[ch]++; 
        }
        map<char, int>::iterator it = mp.begin();
        for(char ch: s){
            if(isVowel(ch)){
                it->second--;
                t += it->first;
                if(it->second == 0) it++;
            } else {
                t += ch;
            }
        }
        return t;
    }
};
