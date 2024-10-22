class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hashMap;
        for(int i = 0;i < n;i++) {
            if(nums[i]%2==0)hashMap[nums[i]]++;
        }
        int maxCount = 0;
        int maxElement = -1;

        for(auto it: hashMap){
            if(it.second == maxCount){
                maxElement = min(maxElement, it.first);
            }
            if(it.second > maxCount){
                maxCount = it.second;
                maxElement = it.first;
            }
        }

        return maxElement;
    }
};
