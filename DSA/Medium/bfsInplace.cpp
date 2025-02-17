class Solution {
public:
    int isValid(int i, int j, int m, int n){
        return (i >= 0 && j >= 0 && i < m && j < n);
    }
    void bfs(vector<vector<char>>& grid, int i, int j, int m, int n){
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        q.push({i, j});
        while(!q.empty()){
            auto [curI, curJ] = q.front();
            q.pop();
            for(auto [dirI, dirJ]: dir){
                dirI += curI, dirJ += curJ;
                if((isValid(dirI, dirJ, m, n)) && (grid[dirI][dirJ] == '1')){
                    grid[dirI][dirJ] = '0';
                    q.push({dirI, dirJ});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    bfs(grid, i, j, m, n);
                }
            }
        }
        return cnt;
    }
};
