class Solution {
    inline int compress(vector<char>& chars, int left){
        int right = left, count = 0;
        while(right < chars.size() && chars[right] == chars[left]){
            right++;
            count++;
        }
        return count;
    }
public:
    int compress(vector<char>& chars) {
        int i = 0, len = 0, n = chars.size();
        while(i < chars.size()){
            int groupCount = compress(chars, i);
            if(groupCount > 1){
                string count = to_string(groupCount);
                for(char digit: count) chars[++i] = digit;
                chars.erase(chars.begin() + i + 1, chars.begin() + i + groupCount - count.size());
            }
            i++;
        }
        return chars.size();
    }
};
