class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        int n = code.size();
        vector<int> result(n, 0);
        if(k==0) return result;

        for(int i = 0;i < n;i++){
            if(k > 0){
                int ind = ((i+1 )% n), c = 0, sum = 0;
                while(c < k){
                    sum = sum + code[ind];
                    ind = (ind+1) % n;
                    c++;
                }
                result[i] = sum;
            }
            else if (k < 0){
                int ind = (i - 1 + n) % n, c = 0, sum = 0;
                while(c < abs(k)){
                    sum = sum + code[ind];
                    ind = (ind - 1 + n) % n;
                    c++;
                }
                result[i] = sum;
            }
        }
        return result;
    }
};
