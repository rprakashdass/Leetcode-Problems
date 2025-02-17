class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col, int m, int n){
        if(row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == '0') return;
        grid[row][col] = '0';
        dfs(grid, row, col+1, m, n);
        dfs(grid, row, col-1, m, n);
        dfs(grid, row+1, col, m, n);
        dfs(grid, row-1, col, m, n);
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j, m, n);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
