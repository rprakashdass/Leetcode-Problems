class Solution {
private:
    string leftRotate(string s, int k){
        int n = s.size();
        s = s.substr(k, n) + s.substr(0, k);
        return s;
    }
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        for(int i = 0;i < n;i++){
            string leftRotated = leftRotate(s, i);
            if(leftRotated == goal) return true;
        }
        return false;
    }
};
