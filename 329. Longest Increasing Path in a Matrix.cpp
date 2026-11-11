// BFS
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> indegree(m, vector<int>(n, 0));
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Calculate indegree
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (auto [dx, dy] : dirs) {
                    int x = i + dx;
                    int y = j + dy;

                    if (x >= 0 && x < m && y >= 0 && y < n &&
                        matrix[i][j] > matrix[x][y]) {
                        indegree[i][j]++;
                    }
                }
            }
        }
        queue<pair<int, int>> q;

        // Push all indegree == 0 nodes
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (indegree[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        int pathLength = 0;

        // BFS (Topological Sort)
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [i, j] = q.front();
                q.pop();

                for (auto [dx, dy] : dirs) {
                    int x = i + dx;
                    int y = j + dy;

                    if (x >= 0 && x < m && y >= 0 && y < n &&
                        matrix[i][j] < matrix[x][y]) {
                        indegree[x][y]--;
                        if (indegree[x][y] == 0) {
                            q.push({x, y});
                        }
                    }
                }
            }
            pathLength++;
        }
        return pathLength;
    }
};

// DFS
// class Solution {
// public:
//     vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
//     int longestIncreasingPath(vector<vector<int>>& matrix) {
//         int m = matrix.size()
//         int n = matrix[0].size();
//         int res = 1;
//         vector<vector<int>> dp(m, vector<int>(n, 0));
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 res = max(res, dfs(matrix, dp, i, j));
//             }
//         }
//         return res;
//     }
//     int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j) {
//         if (dp[i][j] > 0) return dp[i][j];
//         int mx = 1, m = matrix.size(), n = matrix[0].size();
//         for (auto a : dirs) {
//             int x = i + a[0], y = j + a[1];
//             if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j]) continue;
//             int len = 1 + dfs(matrix, dp, x, y);
//             mx = max(mx, len);
//         }
//         dp[i][j] = mx;
//         return mx;
//     }
// };
