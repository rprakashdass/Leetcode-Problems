class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        unordered_map<int, int>hashMap;

        for(int i = 0;i < n;i++) {
            hashMap[nums[i]]++;
        }
        
        vector<pair<int, int>> frequencyList(
            hashMap.begin(), hashMap.end()
        );

        sort(frequencyList.begin(), frequencyList.end(), [](pair<int, int>& a, pair<int, int>& b){
            return a.second > b.second;
        });

        for(int i = 0;i < k;i++){
            result.push_back(frequencyList[i].first);
        }

        return result;
    }
};
