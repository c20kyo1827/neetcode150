// // Kruskal's algorithm
// class Solution {
// public:
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         std::vector<int> edges(points.size(), INT_MAX); // cost
        
//         // Start from points[0]
//         for(size_t i=1 ; i<points.size() ; i++) {
//             edges[i] = distance(points[0][0], points[0][1], points[i][0], points[i][1]);
//         }

//         // Pick the minimal cost and then start from the connected point
//         int ans = 0;
//         for(size_t i=1 ; i<points.size() ; i++) {
//             auto it = min_element(edges.begin(), edges.end());
//             ans += *it;

//             int next = it - edges.begin();
//             *it = INT_MAX; // Already pick the edge
//             for(size_t j=0 ; j<points.size() ; j++) {
//                 if (edges[j] == INT_MAX)
//                     continue;
//                 edges[j] = 
//                     std::min(edges[j], 
//                         distance(points[j][0], points[j][1], points[next][0], points[next][1]));
//             }
//         }
//         return ans;
//     }

//     int distance(int x1, int y1, int x2, int y2) {
//         return abs(x1 - x2) + abs(y1 - y2);
//     }
// };

// Prim's algorithm
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        
        // edges[i] stores the minimum cost to connect point i to the current MST
        vector<int> edges(n, INT_MAX);
        vector<bool> visited(n, false);
        
        edges[0] = 0;
        
        for (int i = 0; i < n; ++i) {
            int current = -1;
            
            // Find the unvisited node with the smallest distance to the MST
            for (int j = 0; j < n; ++j) {
                if (!visited[j] &&
                    (current == -1 || edges[j] < edges[current]) ) {
                    current = j;
                }
            }
            
            visited[current] = true;
            ans += edges[current];
            
            // Update the edges from the "current"
            for (int next = 0; next < n; ++next) {
                if (!visited[next]) {
                    int dist = distance(
                            points[current][0], points[current][1],
                            points[next][0], points[next][1]);
                    edges[next] = min(edges[next], dist);
                }
            }
        }
        
        return ans;
    }

    int distance(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }
};
