// // DFS
// class Solution {
// public:
//     vector<string> findItinerary(vector<vector<string>> tickets) {
//         vector<string> res;
//         unordered_map<string, multiset<string>> graph;
//         for (auto ticket : tickets) {
//             graph[ticket[0]].insert(ticket[1]);
//         }
//         dfs(graph, "JFK", res);
//         return vector<string> (res.rbegin(), res.rend());
//     }
//     void dfs(unordered_map<string, multiset<string>>& graph, string s, vector<string>& res) {
//         while (graph[s].size()) {
//             string t = *graph[s].begin();
//             graph[s].erase(graph[s].begin());
//             dfs(graph, t, res);
//         }
//         res.push_back(s);
//     }
// };

// Iterative
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>> tickets) {
        vector<string> res;
        stack<string> st{{"JFK"}};
        unordered_map<string, multiset<string>> graph;
        for (auto ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }
        while (!st.empty()) {
            string t = st.top(); 
            if (graph[t].empty()) {
                res.insert(res.begin(), t);
                st.pop();
            } else {
                st.push(*graph[t].begin());
                graph[t].erase(graph[t].begin());
            }
        }
        return res;
    }
};
