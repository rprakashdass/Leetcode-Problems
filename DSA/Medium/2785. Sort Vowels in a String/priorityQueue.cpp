class Solution {
public:
    string sortVowels(string s) {
        string t = "";
        auto isVowel = [](char ch){
            ch = tolower(ch);
            return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
        };
        priority_queue<char, vector<char>, greater<char>> pq;
        for(char ch: s){
            if(isVowel(ch)) pq.push(ch); 
        }
        for(char ch: s){
            if(isVowel(ch)){
                t += pq.top();
                pq.pop();
            } else {
                t += ch;
            }
        }
        return t;
    }
};
