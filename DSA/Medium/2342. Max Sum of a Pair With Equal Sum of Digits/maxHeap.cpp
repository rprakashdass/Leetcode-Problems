class Solution {
private:
        int getSum(int num){
            int sum = 0;
            while(num > 0){
                sum += num%10;
                num /= 10;
            }
            return sum;
        }
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return -1;
        unordered_map<int, priority_queue<int>> hashMap;
        bool flag = true;
        for(int i = 0;i < n;i++){
            int sum = getSum(nums[i]);
            if(hashMap.find(sum) != hashMap.end()) flag = false;
            hashMap[sum].push(nums[i]);
        }
        if(flag) return -1;
        int maxm = -1;
        for(auto it: hashMap){
            if(it.second.size() < 2) continue;
            int x = it.second.top();
            it.second.pop();
            int y = it.second.top();
            maxm = max(maxm, x + y);
        }
        return maxm;
    }
};
