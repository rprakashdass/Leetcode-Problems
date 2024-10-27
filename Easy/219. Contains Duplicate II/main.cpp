class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l = 0;
        unordered_map<int,int> hashMap;
        for(int r = 0;r < nums.size();r++){
            if(abs(r-l) > k){
                hashMap[nums[l++]]--;
            } 
            if(hashMap[nums[r]] > 0) return true;
            hashMap[nums[r]]++;
        }
        return false;
    }
};
