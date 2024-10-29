class Solution {
public:
    int findLHS(vector<int>& nums) {
        int longest = 0;
        unordered_map<int, int> hashMap;
        for(int i = 0;i < nums.size();i++){
            hashMap[nums[i]]++;
            if(hashMap[nums[i]+1] > 0) 
                longest = max(longest, hashMap[nums[i]+1] + hashMap[nums[i]]);
            if(hashMap[nums[i]-1] > 0) 
                longest = max(longest, hashMap[nums[i]-1] + hashMap[nums[i]]);
        }
        return longest;
    }
};
