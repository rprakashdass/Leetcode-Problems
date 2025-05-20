// Time Complexity: O(M*N) — each cell is processed at most once
// Space Complexity: O(M*N) — queue can grow to hold all cells in worst case

class Solution {
    int m, n;
    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    bool isValid(const int i, const int j){
        return (i >= 0 && j >= 0 && i < m && j < n);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                } else {
                    mat[i][j] = -1;
                }
            }
        }
        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();
            for(auto [dx, dy]: dir){
                int nx = i + dx, ny = j + dy;
                if(isValid(nx, ny) && mat[nx][ny] == -1){
                    mat[nx][ny] = mat[i][j] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return mat;
    }
};
