// Brute Approach
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        for(int i = 0;i < n;i++){
            int j = i + needle.size();
            int count = 0;
            for(int k = i;k < j;k++){
                if(haystack[k] != needle[count])
                    break;
                count++;
            }
            if(count == needle.size())
                return i;
        }
        return -1;
    }
};

// Better Approach (two pointer approach)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if(n <= 1) return (haystack[0] == needle[0])-1;

        for(int i = 0;i < n;i++){
            int j = 0;
            while(j < m && haystack[i+j] == needle[j])
                j++;
            
            if(j == m) return i;
        }

        return -1;
    }
}; 
