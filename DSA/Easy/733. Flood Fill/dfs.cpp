// Time Complexity: O(M*N)
// Space Complexity; O(M*N) stack space

class Solution {
    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    bool isValid(int i, int j, int m, int n){
        return (i >= 0 && j >= 0 && i < m && j < n);
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int &originalColor, int &color){
        if(image[sr][sc] != originalColor) return;
        image[sr][sc] = color;
        for(auto[dirI, dirJ]: dir){
            int newI = sr + dirI;
            int newJ = sc + dirJ;
            if(isValid(newI, newJ, image.size(), image[0].size())){
                dfs(image, newI, newJ, originalColor, color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int &color) {
        int originalColor = image[sr][sc];
        if(color == originalColor) return image;
        dfs(image, sr, sc, originalColor, color);
        return image;
    }
};
