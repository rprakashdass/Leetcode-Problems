class Solution {
    unordered_map<char, int> symbols = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };

public:
    int romanToInt(string s) {
        int integer = 0;
        int prev = 0;
        for(int i = s.size()-1;i >= 0;i--) {
            int value = symbols[s[i]];
            // In Roman numerals, if a smaller value symbol appears before a larger one,
            // it means subtraction (like IV = 4, IX = 9, etc.).
            // Since we're iterating from the end, we subtract if the current value is less than the previous.
            if(value < prev) integer -= value;
            else integer += value;
            prev = value;
        }
        return integer;
    }
};
