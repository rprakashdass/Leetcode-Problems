class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        auto comparator = [](const pair<float, vector<int>>& a, const pair<float, vector<int>>& b) {
            return a.first < b.first;
        };
        priority_queue<pair<float, vector<int>>, vector<pair<float, vector<int>>>, decltype(comparator)> maxHeap;

        for(vector<int> point: points) {
            int x = point[0], y = point[1];
            float distance = sqrt(((x - 0) * (x - 0)) + ((y - 0) * (y - 0)));
            if(maxHeap.size() < k) {
                maxHeap.push(make_pair(distance, point));
            } else if (distance < maxHeap.top().first) {
                maxHeap.pop();
                maxHeap.push(make_pair(distance, point));
            }
        }

        vector<vector<int>> result;
        while(!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};
