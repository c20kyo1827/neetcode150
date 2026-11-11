// // DP
// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         vector<int> dp(cost.size());
//         dp[0] = cost[0];
//         dp[1] = cost[1];
//         for(int i=2 ; i<cost.size() ; i++) {
//             dp[i] = cost[i] + std::min(dp[i-2], dp[i-1]);
//         }
//         return std::min(dp[cost.size()-2], dp[cost.size()-1]);
//     }
// };

// O(1) space
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev2 = cost[0];
        int prev1 = cost[1];

        for (int i = 2; i < cost.size(); ++i) {
            int cur = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = cur;
        }

        return min(prev1, prev2);
    }
};
