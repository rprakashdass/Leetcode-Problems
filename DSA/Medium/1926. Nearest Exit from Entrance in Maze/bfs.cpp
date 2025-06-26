class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));        
        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = true;

        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        int steps = 0;
        while(!q.empty()) {
            for(int _ = q.size();_ > 0;_--) {
                auto [x, y] = q.front();
                q.pop();

                if((x != entrance[0] || y != entrance[1]) &&
                (x == 0 || x == m-1 || y == 0 || y == n-1)) {
                    return steps;
                }

                for(auto [dx, dy] : dir) {
                    int newX = x + dx, newY = y + dy;
                    if(!isValid(newX, newY, m, n) || visited[newX][newY]) continue;
                    if(maze[newX][newY] == '.') {
                        q.push({newX, newY});
                        visited[newX][newY] = true;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
