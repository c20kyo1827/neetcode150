/*

1 -> 2
2 -> 3
3 -> ... 
return -1

1 -> 3, 4
2 -> 3, 4
3 -> 4
4 -> ...
return 4

*/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        std::vector<int> trustFrom(n, 0);
        std::vector<int> trustTo(n, 0);
        for(auto& data : trust) {
            trustFrom[data[1]-1]++;
            trustTo[data[0]-1]++;
        }

        for(size_t i=0 ; i<n ; i++) {
            if(trustTo[i] == 0 && trustFrom[i] == n-1)
                return i+1;
        }
        return -1;
    }
};
