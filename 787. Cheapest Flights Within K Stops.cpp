// // TLE
// class Solution {
//     unordered_map<int, vector<pair<int, int>>> graph;
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         int res = INT_MAX;
//         graph.clear();
//         unordered_set<int> visited{{src}};
//         for (auto flight : flights) {
//             graph[flight[0]].push_back({flight[1], flight[2]});
//         }
//         traverse(src, dst, k, visited, 0, res);
//         return (res == INT_MAX) ? -1 : res;
//     }

//     void traverse(int cur, int dst, int k, unordered_set<int> visited, int curOut, int& res) {
//         if(cur == dst) {
//             res = curOut;
//             return;
//         }
//         if(k < 0)
//             return;
//         for(auto& [node, wght] : graph[cur]) {
//             if(visited.count(node) || curOut + wght > res)
//                 continue;
//             visited.insert(node);
//             traverse(node, dst, k-1, visited, curOut + wght, res);
//             visited.erase(node);
//         }
//     }
// };

// // BFS
// // MLE
// class Solution {
//     unordered_map<int, vector<pair<int, int>>> graph;
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         int res = INT_MAX, cnt = 0;
//         graph.clear();
//         for (auto flight : flights) {
//             graph[flight[0]].push_back({flight[1], flight[2]});
//         }

//         queue<vector<int>> q{{{src, 0}}};
//         while (!q.empty()) {
//             for (int i = q.size(); i > 0; --i) {
//                 auto t = q.front(); q.pop();
//                 if (t[0] == dst) res = min(res, t[1]);
//                 for (auto& [node, wght] : graph[t[0]]) {
//                     if (t[1] + wght > res) continue;
//                     q.push({node, t[1] + wght});
//                 }
//             }
//             if (cnt++ > k) break;
//         }
//         return (res == INT_MAX) ? -1 : res;
//     }
// };

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(k + 2, vector<int>(n, INT_MAX-1e5));
        dp[0][src] = 0;
        for (int i = 1; i <= k + 1; ++i) {
            dp[i][src] = 0;
            for (auto x : flights) {
                dp[i][x[1]] = min(dp[i][x[1]], dp[i - 1][x[0]] + x[2]);
            }
        }
        return (dp[K + 1][dst] >= INT_MAX-1e5) ? -1 : dp[K + 1][dst];
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> dp(n, INT_MAX-1e5);
        dp[src] = 0;
        for (int i = 0; i <= K; ++i) {
            vector<int> t = dp;
            for (auto x : flights) {
                t[x[1]] = min(t[x[1]], dp[x[0]] + x[2]);
            }
            dp = t;
        }
        return (dp[dst] >= INT_MAX-1e5) ? -1 : dp[dst];
    }
};
