class Solution {
    inline static vector<string> keyboard = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void combinations(vector<string>& result, string digits, string combination, int i, int& n){
    if(i == n){
        result.push_back(combination);
        return;
    }
    string letters = keyboard[digits[i] - '0'];
    for(int j = 0;j < letters.size();j++){
        combinations(result, digits, combination + letters[j], i+1, n);
    }
}

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        int n = digits.size();
        if(n == 0) return result;
        combinations(result, digits, "", 0, n);
        return result;
    }
};
