class Solution {
    int m, n;
    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    bool isValid(const int i, const int j){
        return (i >= 0 && j >= 0 && i < m && j < n);
    };
    pair<bool, int> dfs(vector<vector<int>>& grid, int i, int j){
        if(!isValid(i, j)) return {false, 0};
        if(grid[i][j] == 0) return {true, 0};
        grid[i][j] = 0;
        bool isEnclave = (i != 0 && j != 0 && i != m-1 && j != n-1);
        int count = 1;
        for(auto[dirI, dirJ]: dir){
            int newI = i + dirI;
            int newJ = j + dirJ;
            auto [isChildEnclave, childCount] = dfs(grid, newI, newJ);
            isEnclave = isEnclave && isChildEnclave;
            count += childCount;
        }
        return {isEnclave, count};
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int count = 0;
        m = grid.size(), n = grid[0].size();
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1){
                    auto[isEnclave, landCount] = dfs(grid, i, j);
                    if(isEnclave) count += landCount;
                }
            }
        }
        return count;
    }
};
