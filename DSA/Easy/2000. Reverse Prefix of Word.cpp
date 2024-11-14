class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();
        int r = word.find(ch);
        int l = 0;
        cout << l;

        if(l!=-1)
        while(l < r){
            swap(word[l], word[r]);
            l++;
            r--;
        }

        return word;
    }
};
