// Recursive + check cycle
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> nodeToNeighbors;
        for (auto edge : edges) {
            if (hasCycle(edge[0], edge[1], nodeToNeighbors, -1)) return edge;
            nodeToNeighbors[edge[0]].insert(edge[1]);
            nodeToNeighbors[edge[1]].insert(edge[0]);
        }
        return {};
    }

    bool hasCycle(int cur, int target, unordered_map<int, unordered_set<int>>& nodeToNeighbors, int pre) {
        if (nodeToNeighbors[cur].count(target)) return true;
        for (int next : nodeToNeighbors[cur]) {
            if (next == pre) continue;
            if (hasCycle(next, target, nodeToNeighbors, cur)) return true;
        }
        return false;
    }
};

// Non-recursive
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> nodeToNeighbors;
        for (auto edge : edges) {
            queue<int> q{{edge[0]}};
            unordered_set<int> s{{edge[0]}};
            while (!q.empty()) {
                auto t = q.front(); q.pop();
                if (nodeToNeighbors[t].count(edge[1])) return edge;
                for (int next : nodeToNeighbors[t]) {
                    if (s.count(next)) continue;
                    q.push(next);
                    s.insert(next);
                }
            }
            nodeToNeighbors[edge[0]].insert(edge[1]);
            nodeToNeighbors[edge[1]].insert(edge[0]);
        }
        return {};
    }
};

// Union-find
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> root(1001, -1);
        for (auto edge : edges) {
            int x = find(root, edge[0]), y = find(root, edge[1]);
            if (x == y) return edge;
            root[x] = y;
        }
        return {};
    }
    int find(vector<int>& root, int i) {
        while (root[i] != -1) {
            i = root[i];
        }
        return i;
    }
};
