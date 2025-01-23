class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for(auto ch: s) mp[ch]++;
        int length = 0, hasOdd = 0;
        for(auto it: mp){
            int num = it.second;
            if(num%2==0) length += num;
            else length += (num - 1), hasOdd = 1;
        }
        return (hasOdd) ? length + 1 : length;
    }
};
