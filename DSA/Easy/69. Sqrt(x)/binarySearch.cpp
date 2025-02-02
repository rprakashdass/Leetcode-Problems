class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;
        long long ans = 0;
        long long left = 1, right = x;
        while(left <= right){
            long long mid = (left+right)/2;
            if(mid*mid == x) return mid;
            else if((mid * mid) > x){
                right = mid-1;
            }else{
                ans = mid;
                left = mid+1;
            }
        }
        return ans;
    }
};
