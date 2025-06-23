class Solution {
public:
    bool isDivisor(const string &str1, const string &str2, const string &str) {
        int m = str1.size(), n = str2.size(), len = str.size();
        if(m % len  || n % len) {
            return false;
        }
        int fact1 = m / len, fact2 = n / len;
        string s1 = "";
        string s2 = "";
        for (int i = 0; i < fact1; ++i) s1 += str;
        for (int i = 0; i < fact2; ++i) s2 += str;
        return str1 == s1 && str2 == s2;
    }
    string gcdOfStrings(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        for(int len = min(m, n);len > 0;len--) {
            string str = str1.substr(0, len);
            if(isDivisor(str1, str2, str)) return str;
        }
        return "";
    }
};
