class Solution {
public:
    int maxVowels(string s, int k) {
        int vowelCount = 0, left = 0, maxCount = 0;
        auto isVowel = [](const char ch){
            return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
        };
        for(int right = 0;right < s.size();right++){
            if(isVowel(s[right])) vowelCount++;
            if(right-left+1 == k){
                maxCount = max(maxCount, vowelCount);
                if(isVowel(s[left])) vowelCount--;
                left++;
            }
        }
        return maxCount;
    }
};
