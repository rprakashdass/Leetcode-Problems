class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(n > 0 && seen.find(n) == seen.end()){
            seen.insert(n);
            int sum = 0;
            while(n > 0){
                int last_digit = n%10;
                sum += (last_digit*last_digit);
                n/=10;
            }
            if(sum == 1) return true;
            n = sum;
        }
        return false;
    }
};
