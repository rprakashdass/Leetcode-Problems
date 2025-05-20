class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        return (i >= 0 && j >= 0 && i < m && j < n);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if(color == originalColor) return image;
        image[sr][sc] = color;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while(!q.empty()){
            auto [curI, curJ] = q.front();
            q.pop();
            for(auto[dirI, dirJ]: dir){
                int newI = curI + dirI;
                int newJ = curJ + dirJ;
                if(isValid(newI, newJ, image.size(), image[0].size()) && image[newI][newJ] == originalColor){
                    image[newI][newJ] = color;
                    q.push({newI, newJ});
                }
            }
        }
        return image;
    }
};
