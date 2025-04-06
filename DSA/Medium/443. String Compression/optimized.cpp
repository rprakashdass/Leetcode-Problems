class Solution {
public:
    int compress(vector<char>& chars) {
        int left = 0, right = 0, n = chars.size();
        while(right < n){
            int groupCount = 0;
            char ch = chars[right];
            chars[left++] = ch;
            while(right < n && chars[right] == ch){
                right++;
                groupCount++;
            }
            if(groupCount > 1){
                string count = to_string(groupCount);
                for(char digit: count) {
                    chars[left++] = digit;
                }
            }
        }
        return left;
    }
};
