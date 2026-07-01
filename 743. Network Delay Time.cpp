// Single source to all destination

// Dijkstra : 
// weight > 0
// No negative cyclic
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int res = 0;
        vector<vector<int>> edges(N+1, vector<int>(N+1, -1));
        queue<int> q{{K}};
        vector<int> dist(N + 1, INT_MAX);
        dist[K] = 0;
        for (auto e : times) edges[e[0]][e[1]] = e[2];
        while (!q.empty()) {
            unordered_set<int> visited;
            for (int i = q.size(); i > 0; --i) {
                int u = q.front(); q.pop();
                for (int v = 1; v <= N; ++v) {
                    if (edges[u][v] != -1 && dist[u] + edges[u][v] < dist[v]) {
                        if (!visited.count(v)) {
                            visited.insert(v);
                            q.push(v);
                        }
                        dist[v] = dist[u] + edges[u][v];
                    }
                }
            }
        }
        for (int i = 1; i <= N; ++i) {
            if (dist[i] == INT_MAX)
                return -1;
            res = max(res, dist[i]);
        }
        return res;
    }
};

// // Bellman-Ford 
// class Solution {
// public:
//     int networkDelayTime(vector<vector<int>>& times, int N, int K) {
//         int res = 0;
//         vector<int> dist(N + 1, INT_MAX);
//         dist[K] = 0;
//         for (int i = 1; i < N; ++i) {
//             for (auto e : times) {
//                 // K -> v 
//                 // K -> u -> v 
//                 int u = e[0], v = e[1], w = e[2];
//                 if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
//                     dist[v] = dist[u] + w;
//                 }
//             }
//         }
//         for (int i = 1; i <= N; ++i) {
//             if (dist[i] == INT_MAX)
//                 return -1;
//             res = max(res, dist[i]);
//         }
//         return res;
//     }
// };
