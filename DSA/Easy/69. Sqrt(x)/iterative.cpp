class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;
        long long ans = 0;
        for(long long i = 1;i <= x/2;i++){
            if(i*i > x){
                return ans;
            }
            ans = i;
        }
        return ans;
    }
};
