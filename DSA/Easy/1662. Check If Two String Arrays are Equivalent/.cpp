class Solution {
private:

    string concat(vector<string> word1){
        string word3;
        for(auto a: word1){
            word3 += a;
        }
        return word3;
    }
    
public:

    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {

        return concat(word1) == concat(word2);

    }
};
