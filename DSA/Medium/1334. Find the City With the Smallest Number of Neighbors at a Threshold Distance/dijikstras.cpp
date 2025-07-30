class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int, int>>> adj(n);
        for(vector<int> e: edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int minReachable = n, reachableCity = -1;
        for(int i = 0;i < n;i++) {
            vector<int> dist(n, INT_MAX);
            dist[i] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            pq.push({0, i});
            while(!pq.empty()) {
                auto [_, u] = pq.top();
                pq.pop();
                for(auto [node, w]: adj[u]) {
                    if(dist[node] > dist[u] + w) {
                        dist[node] = dist[u] + w;
                        pq.push({dist[node], node});
                    }
                }
            }
            
            int count = 0;
            for(int j = 0;j < n;j++) {
                if(i != j && dist[j] <= threshold) {
                    count++;
                }
            }
            if(count <= minReachable) {
                minReachable = count;
                reachableCity = i;
            }
        }
        return reachableCity;
    }
};
