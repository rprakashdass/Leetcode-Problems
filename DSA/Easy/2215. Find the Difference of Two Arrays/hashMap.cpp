class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        unordered_map<int, int> a, b;
        for(int num1: nums1){
            a[num1]++;
        }
        for(int num2: nums2){
            if(a.find(num2) != a.end()){
                a[num2] = INT_MIN;
            } else {
                b[num2]++;
            }
        }
        for(auto [key, value]: a){
            if(value > 0) {
                ans[0].push_back(key);
            }
        }
        for(auto [key, value]: b){
            if(value > 0) {
                ans[1].push_back(key);
            }
        }
        return ans;
    }
};
