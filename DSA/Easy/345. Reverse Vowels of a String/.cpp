class Solution {
public:
    string reverseVowels(string s) {
        auto isVowel = [](char& a){
            char l = tolower(a);
            return (l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u'); 
        };
        int n = s.size();
        int rp = n-1, lp = 0;
        while(lp < rp){
            if(!isVowel(s[lp])) lp++;
            else if(!isVowel(s[rp])) rp--;
            else {
                swap(s[lp], s[rp]);
                lp++;rp--;
            }
        }
        return s;
    }
};
