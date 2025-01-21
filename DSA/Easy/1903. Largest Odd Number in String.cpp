class Solution {
public:
    string largestOddNumber(string num) {
        int index = num.length();
        while(index >= 0){
            int digit = num[index];
            if(digit%2 != 0) return num.substr(0, index+1);
            index--;
        }
        return "";
    }
};
