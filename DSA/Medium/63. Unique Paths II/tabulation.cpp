class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        grid[0][0] = (grid[0][0] == 1) ? 0 : 1;

        // fill 1st column
        for(int j = 1;j < n;j++) {
            // if any 1 found, everything should be blocked
            grid[0][j] = (grid[0][j] == 1) ? 0 : grid[0][j-1];
        }

        // fill 1st row
        for(int i = 1;i < m;i++) {
            grid[i][0] = (grid[i][0] == 1) ? 0 : grid[i-1][0];
        }

        for(int i = 1; i < m;i++) {
            for(int j = 1;j < n;j++) {
                if(grid[i][j] != 1) {
                    grid[i][j] = grid[i-1][j] + grid[i][j-1];
                } else {
                    grid[i][j] = 0;
                }
            }
        }
        return grid[m-1][n-1];
    }
};
