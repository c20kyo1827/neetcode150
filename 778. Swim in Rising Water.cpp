// class Solution {
// public:
//     std::vector<std::vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
//     int swimInWater(vector<vector<int>>& grid) {
//         int res = 0, n = grid.size();
//         std::unordered_set<int> visited;
//         auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
//             return a.first > b.first;
//         };
//         // first -> water level
//         // second -> x_coord * n + y_coord
//         std::priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp) > q;
//         q.push({grid[0][0], 0});
//         while (!q.empty()) {
//             int i = q.top().second / n, j = q.top().second % n;
//             q.pop();
//             res = std::max(res, grid[i][j]);
//             if (i == n - 1 && j == n - 1)
//                 return res;
//             for (auto dir : dirs) {
//                 int x = i + dir[0], y = j + dir[1];
//                 if (x < 0 || x >= n || y < 0 || y >= n || visited.count(x * n + y))
//                     continue;
//                 visited.insert(x * n + y);
//                 q.push({grid[x][y], x * n + y});
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = grid[0][0], right = n * n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (!helper(grid, mid))
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
    bool helper(std::vector<std::vector<int>>& grid, int mid) {
        int n = grid.size();
        std::unordered_set<int> visited{0};
        std::vector<std::vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        std::stack<int> st{{0}};
        while (!st.empty()) {
            int i = st.top() / n, j = st.top() % n;
            st.pop();
            if (i == n - 1 && j == n - 1)
                return true;
            for (auto dir : dirs) {
                int x = i + dir[0], y = j + dir[1];
                if (x < 0 || x >= n || y < 0 || y >= n || visited.count(x * n + y) || grid[x][y] > mid)
                    continue;
                st.push(x * n + y);
                visited.insert(x * n + y);
            }
        }
        return false;
    }
};
