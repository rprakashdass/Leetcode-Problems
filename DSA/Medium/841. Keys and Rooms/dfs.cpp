class Solution {
public:
    int count = 0;
    void dfs(vector<vector<int>>& rooms, vector<bool> &visited, int src) {
        if(visited[src]) return;
        visited[src] = true;
        count++;
        for(int key: rooms[src]) {
            if(!visited[key]) {
                dfs(rooms, visited, key);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        dfs(rooms, visited, 0);
        return count == rooms.size();
    }
};
