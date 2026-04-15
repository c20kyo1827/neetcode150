class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = 0, numOfFresh = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        queue<vector<int>> q;
        for(int i=0 ; i<m ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j] == 1)
                    numOfFresh++;
            }
        }

        while(!q.empty() && numOfFresh>0) {
            int rotSize = q.size();
            for(int i=0 ; i<rotSize ; i++) {
                auto cur = q.front();
                q.pop();
                for(auto& dir : dirs) {
                    int x = cur[0] + dir[0];
                    int y = cur[1] + dir[1];
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1)
                        continue;
                    grid[x][y] = 2;
                    q.push({x,y});
                    numOfFresh--;
                }
            }
            minutes++;
        }
        return numOfFresh > 0 ? -1 : minutes;
    }
};
