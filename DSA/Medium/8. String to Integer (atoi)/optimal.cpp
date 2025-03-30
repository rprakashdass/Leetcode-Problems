class Solution {
public:
    int myAtoi(string s) {
        int n = s.size(), i = 0;
        // trim leading spaces
        while(i < n && s[i] == ' ') i++;

        // signedness
        bool isNegative = false;
        if(s[i] == '-' || s[i] == '+'){
            if(s[i] == '-'){
                isNegative = true;
            }
            i++;
        }

        // remove leading zeros
        while(i < n && s[i] == '0') i++;

        // conversion & rounding
        int resultInt = 0;
        while(i < n && isdigit(s[i])){
            int digit = s[i] - '0';
            if(resultInt > (INT_MAX - digit) / 10){
                return isNegative ? INT_MIN : INT_MAX;
            }
            resultInt = (resultInt * 10) + digit;
            i++;
        }

        return isNegative ? -resultInt : resultInt;
    }
};
