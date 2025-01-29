class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int source){
        visited[source] = 1;
        for(int node: adj[source]){
            if(!visited[node]){
                dfs(adj, visited, node);
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
                dfs(adjLis, visited, i);
                cnt++;
            }
        }
        return cnt;
    }
};
