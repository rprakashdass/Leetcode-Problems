// Time Complexity: O(M × N)
// Space Complexity: O(M × N)

class Solution {
    int m, n;
    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    bool isValid(const int i, const int j){
        return (i >= 0 && j >= 0 && i < m && j < n);
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        m = isWater.size(), n = isWater[0].size();
        queue<pair<int, int>> q;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(isWater[i][j] == 1){
                    isWater[i][j] = 0;
                    q.push({i, j});
                } else isWater[i][j] = -1;
            }
        }
        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();
            for(auto [dx, dy]: dir){
                int nx = i + dx, ny = j + dy;
                if(isValid(nx, ny) && isWater[nx][ny] == -1){
                    isWater[nx][ny] = isWater[i][j] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return isWater;
    }
};
