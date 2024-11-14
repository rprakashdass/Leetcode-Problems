class Solution {
public:
    string reverseWords(string s) {

        reverse(s.begin(), s.end());

        int left = 0, ind = 0;
        int n = s.size();

        while(ind < n){

            while(ind < n && s[ind] == ' '){
                ind++;
            }

            int start = left;
            while(ind < n && s[ind] != ' '){
                s[left++] = s[ind++];
            }

            reverse(s.begin()+start, s.begin()+left);
            s[left++] = ' ';
            ind++;
        }
        while(left > 0 && s[left-1] == ' '){
            left--;
        }
        s.resize(left);
        return s;
    }
};
