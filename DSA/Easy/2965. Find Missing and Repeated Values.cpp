class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<bool> visited((n * n)+1, false);
        vector<int> result(2, -1);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(visited[grid[i][j]] && result[1] == -1){
                    result[0] = grid[i][j];
                }
                visited[grid[i][j]] = true;
            }
        }
        for(int i = 1;i <= n*n;i++){
            if(!visited[i]) {
                result[1] = i;
            }
        }
        return result;
    }
};
