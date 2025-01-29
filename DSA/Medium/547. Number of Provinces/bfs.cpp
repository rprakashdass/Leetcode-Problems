class Solution {
public:
    void bfs(vector<vector<int>>& adj, vector<bool>& visited, int source){
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int adjNode: adj[node]){
                if(!visited[adjNode]){
                    visited[adjNode] = 1;
                    q.push(adjNode);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjLis(n);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(isConnected[i][j] && i != j){
                    adjLis[i].push_back(j);
                }          
            }
        }
        vector<bool> visited(n, false);
        int cnt = 0;
        for(int i = 0;i < n;i++){
            if(!visited[i]){
                bfs(adjLis, visited, i);
                cnt++;
            }
        }
        return cnt;
    }
};
