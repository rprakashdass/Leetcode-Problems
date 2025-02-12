class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hashMap;
        int maxm = -1;

        auto getSum = [](int num){
            int sum = 0;
            while(num > 0){
                sum += num%10;
                num /= 10;
            }
            return sum;
        };

        for(int num: nums){
            int digitSum = getSum(num);
            if(hashMap.find(digitSum) != hashMap.end()){
                maxm = max(maxm, hashMap[digitSum] + num);
                if(hashMap[digitSum] < num){
                    hashMap[digitSum] = num;
                }
            } else {
                hashMap[digitSum] = num;
            }
        }

        return maxm;
    }
};
