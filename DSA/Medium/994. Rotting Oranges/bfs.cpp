class Solution {
private:
    int isValid(int i, int j, int m, int n){
        return (i >= 0 && j >= 0 && i < m && j < n);
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int freshOrangesCount = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) freshOrangesCount++;
            }
        }
        if(freshOrangesCount == 0) return 0;
        int minutes = 0;
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while(!q.empty()){
            bool isRotted = false;
            for(int i = q.size();i > 0;i--){
                auto [curI, curJ] = q.front();
                q.pop();
                for(auto [dirI, dirJ]: dir){
                    dirI += curI, dirJ += curJ;
                    if((isValid(dirI, dirJ, m, n))){
                        if(grid[dirI][dirJ] == 1){
                            grid[dirI][dirJ] = 2;
                            q.push({dirI, dirJ});
                            freshOrangesCount--; 
                            isRotted = true;
                        }
                    }
                }
            }
            if(isRotted) minutes++;
        }

        return (freshOrangesCount == 0) ? minutes : -1;
    }
};
