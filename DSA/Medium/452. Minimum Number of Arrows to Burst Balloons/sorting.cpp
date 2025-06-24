class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const auto &a, const auto &b) {
            return a[1] < b[1];
        });
        int arrows = 1, prevEnd = points[0][1];
        for(int i = 1;i < points.size();i++) {
            if(points[i][0] > prevEnd) {
                prevEnd = points[i][1];
                arrows++;
            }
        }
        return arrows;
    }
};
