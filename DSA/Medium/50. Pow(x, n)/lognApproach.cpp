class Solution {
public:
    double myPow(double x, long long n) {
        double ans = 1;
        long long N = n;
        if(n < 0)  n = -(n);

        while(n > 0){
            if(n % 2 == 0){
                x = x * x;
                n /= 2; 
            } else{
                ans = ans * x;
                n -= 1;
            }
        }
        
        return (N < 0) ? 1/ans : ans;
    }
};
