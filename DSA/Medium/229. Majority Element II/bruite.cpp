class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        unordered_map<int, int> mp;
        for(int num: nums){
            mp[num]++;
            if(mp[num] == (n/3)+1){
                res.push_back(num); 
            }
        }
        return res;
    }
};
