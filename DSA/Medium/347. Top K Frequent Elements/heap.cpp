class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        auto comparator = [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first > b.first;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparator)> minHeap;
        unordered_map<int, int> counter;

        for(int num: nums) {
            counter[num]++;
        }

        for(auto [num, count]: counter) {
            minHeap.push({count, num});
            if(minHeap.size() > k) minHeap.pop();
        }

        vector<int> result;
        while(!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};
