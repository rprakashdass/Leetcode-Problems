class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& preq) {
        vector<int> inDeg(n, 0);
        vector<vector<int>> adj(n);
        for(vector<int> edge: preq) {
            inDeg[edge[1]]++;
            adj[edge[0]].push_back(edge[1]);
        }
        queue<int> q;
        int count = 0;
        for(int i = 0;i < n;i++) {
            if(inDeg[i] == 0) {
                count++;
                q.push(i);
            }
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int v: adj[u]) {
                inDeg[v]--;
                if(inDeg[v] == 0) {
                    q.push(v);
                    count++;
                }
            }
        }
        return count == n;
    }
};
