class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& preq) {
        vector<int> inDeg(n, 0);
        vector<vector<int>> adj(n);
        for(vector<int> edge: preq) {
            inDeg[edge[0]]++;
            adj[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        for(int i = 0;i < n;i++) {
            if(inDeg[i] == 0) {
                q.push(i);
            }
        }
        vector<int> result;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);

            for(int v: adj[u]) {
                inDeg[v]--;
                if(inDeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        return result.size() == n ? result : vector<int>();
    }
};
