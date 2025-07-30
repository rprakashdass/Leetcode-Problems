class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        int minReachable = n, reachableCity = -1;
        for(int city = 0;city < n;city++) {
            vector<int> dist(n, INT_MAX);
            dist[city] = 0;
            for(int i = 0;i < n;i++) {
                bool improved = false;
                for(vector<int> e: edges) {
                    int u = e[0], v = e[1], w = e[2];
                    if(dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                        improved = true;
                    }
                    if(dist[v] != INT_MAX && dist[u] > dist[v] + w) {
                        dist[u] = dist[v] + w;
                        improved = true;
                    }
                }
                if(!improved) break;
            }
            int count = 0;
            for(int j = 0;j < n;j++) {
                if(city != j && dist[j] <= threshold) {
                    count++;
                }
            }
            if(count <= minReachable) {
                minReachable = count;
                reachableCity = city;
            }
        }
        return reachableCity;
    }
};
