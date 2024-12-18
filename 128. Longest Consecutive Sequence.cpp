// Failed : TLE
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_set<int> numsSet(nums.begin(), nums.end());
//         int longestSize = 0;
//         for(auto& num : numsSet){
//             int curNum = num+1;
//             int curSize = 1;
//             while(numsSet.count(curNum)){
//                 curNum++;
//                 curSize++;
//             }
//             longestSize = longestSize<curSize ? curSize : longestSize;
//         }
//         return longestSize;
//     }
// };

// Hash
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_set<int> numsSet(nums.begin(), nums.end());
//         int longestSize = 0;
//         for(auto& num : nums){
//             if (!numsSet.count(num)) continue;
//             numsSet.erase(num);
//             int leftNum = num-1, rightNum = num+1;
//             while(numsSet.count(leftNum)) numsSet.erase(leftNum--);
//             while(numsSet.count(rightNum)) numsSet.erase(rightNum++);
//             longestSize = max(longestSize, rightNum-leftNum-1);

//         }
//         return longestSize;
//     }
// };

// Union find
class UnionFind {
    public:
    UnionFind(vector<int>& nums){
        for(auto& num : nums){
            parent[num] = num;
            numOfNodes[num] = 1;
        }
    }

    int find(int i){ // path compression
        if (parent.count(i) <= 0){
           assert(false); // Should not occur
        }
        if (i != parent[i]){
            return find(parent[i]);
        }
        return parent[i];
    }

    void Union(int x, int y){
        int root_x = find(x);
        int root_y = find(y);
        if (root_x != root_y){
            if (numOfNodes[root_x] > numOfNodes[root_y]){
                parent[root_y] = root_x;
                numOfNodes[root_x] += numOfNodes[root_y];
            }
            else if (numOfNodes[root_y] > numOfNodes[root_x]){
                parent[root_x] = root_y;
                numOfNodes[root_y] += numOfNodes[root_x];
            }
            else{
                parent[root_y] = root_x;
                numOfNodes[root_x] += numOfNodes[root_y];
            }
        }
    }

    int getNumOfNodes(int x){
        return numOfNodes[find(x)];
    }

    private:
        map<int, int> parent;
        map<int, int> numOfNodes;
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> numsSet(nums.begin(), nums.end());
        UnionFind uf(nums);
        int longestSize = 0;
        for(auto& num : numsSet){
            if(numsSet.count(num-1) > 0) uf.Union(num, num-1);
            if(numsSet.count(num+1) > 0) uf.Union(num, num+1);
            longestSize = max(longestSize, uf.getNumOfNodes(num));
        }
        return longestSize;
    }
};

