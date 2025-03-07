class Solution {
public:
    bool isPrime(int num){
        if(num <= 1) return false;
        for(int i = 2;i <= sqrt(num);i++){
            if(num % i == 0) return false;
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        int minDiff = INT_MAX, ele1 = -1, ele2 = -1, prev = -1;
        vector<int> pair(2, -1);
        if(isPrime(left)) prev = left;
        for(int i = left + 1;i <= right;i++){
            if(isPrime(i)){
                int diff = i - prev;
                if(minDiff >= diff && prev != -1){
                    if(minDiff == diff && pair[0] >= i){
                        pair[0] = prev, pair[1] = i;    
                    } else if(minDiff > diff){
                        pair[0] = prev, pair[1] = i;
                    }
                    minDiff = diff;
                }
                prev = i;
            }
        }
        return pair;
    }
};
