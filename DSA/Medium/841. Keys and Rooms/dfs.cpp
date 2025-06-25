class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<bool> &visited, int src) {
        visited[src] = true;
        for(int key: rooms[src]) {
            if(!visited[key]) {
                dfs(rooms, visited, key);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<vector<int>> adj;
        vector<bool> visited(rooms.size(), false);
        dfs(rooms, visited, 0);
        for(int i = 0;i < rooms.size();i++) {
            if(!visited[i]) return false;
        }
        return true;
    }
};
