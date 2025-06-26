class Solution {
public:
    bool isValid(int n, int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < n;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) {
            return -1;
        }
        queue<tuple<int, int, int>> q;
        vector<vector<bool>> visited(n, vector<bool> (n, false));
        vector<pair<int, int>> dir = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0},
            {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
        };

        q.push({1, 0, 0});
        visited[0][0] = true;

        while(!q.empty()) {
            auto [steps, x, y] = q.front();
            q.pop();

            if(x == n-1 && y == n-1) {
                return steps;
            }

            for(const auto &[dx, dy] : dir) {
                int newX = x + dx, newY = y + dy;
                if(!isValid(n, newX, newY) || visited[newX][newY]) {
                    continue;
                }
                if(grid[newX][newY] == 0) {
                    q.push({steps+1, newX, newY});
                    visited[newX][newY] = true;
                }
            }
        }
        return -1;
    }
};
