class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(triangle.size() == 1) return triangle[0][0];
        for(int i = 1;i < n;i++) {
            triangle[i][0] += triangle[i-1][0];
            for(int j = 1;j < triangle[i].size()-1;j++) {
                triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]); 
            }
            triangle[i].back() += triangle[i-1][triangle[i-1].size()-1];
        }
        return *min_element(triangle.back().begin(), triangle.back().end());
    }
};
