class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> frequency;
        int left = 0, right = 0, n = s.size();
        int length = 0, maxfreq = 0, result = 0;
        while(right < n){
            frequency[s[right]]++;
            length = right - left + 1;
            maxfreq = max(maxfreq, frequency[s[right]]);
            while (length - maxfreq > k){
                frequency[s[left]]--;
                length--;
                left++;
            }
            result = max(result, right-left+1);
            right++;
        }
        return result;
    }
};
