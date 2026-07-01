// // BFS
// class Solution {
// public:
//     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
//         if (source == destination) return true;
        
//         std::vector<std::vector<int>> graph(n, std::vector<int>());
//         for(auto edge : edges) {
//             graph[edge[0]].push_back(edge[1]);
//             graph[edge[1]].push_back(edge[0]);
//         }
        
//         std::vector<bool> visited(n, false);
//         std::queue<int> q;
//         visited[source] = true;
//         q.push(source);
//         while(!q.empty()) {
//             auto cur = q.front();
//             q.pop();
//             for(auto next : graph[cur]) {
//                 if (next == destination)
//                     return true;
//                 if (visited[next])
//                     continue;
//                 q.push(next);
//                 visited[next] = true;
//             }
//         }
//         return false;
//     }
// };

// Union find
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        std::vector<int> parents(n);
        std::iota(parents.begin(), parents.end(), 0);
        std::vector<int> rank(n, 1);

        std::function<int(int)> find = [&](int x) {
            if (parents[x] != x)
                parents[x] = find(parents[x]);
            return parents[x];
        };

        auto unin = [&](int x, int y) {
            auto rootX = find(x);
            auto rootY = find(y);
            if (rootX != rootY) {
                if (rank[rootX] > rank[rootY])
                    parents[rootY] = rootX;
                else if(rank[rootX] < rank[rootY])
                    parents[rootY] = rootX;
                else {
                    parents[rootY] = rootX;
                    rank[rootX]++;
                }
            }
        };

        for(auto edge : edges) {
            unin(edge[0], edge[1]);
        }

        return find(source) == find(destination);
    }
};
