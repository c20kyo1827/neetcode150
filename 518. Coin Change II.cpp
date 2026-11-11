class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, 0));
        dp[0][0] = 1;
        for(int i=1 ; i<=coins.size() ; i++) {
            dp[i][0] = 1;
            for(int j=1 ; j<=amount ; j++){
                if (j >= coins[i-1] && dp[i-1][j] > INT_MAX - dp[i][j-coins[i-1]])
                    dp[i][j] = INT_MAX;
                else {
                    dp[i][j] = dp[i-1][j] + 
                        (j >= coins[i-1] ? dp[i][j-coins[i-1]] : 0);
                }
            }
        }
        return dp[coins.size()][amount];
    }
};

// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         vector<long> dp(amount + 1, 0);
//         dp[0] = 1;
//         for (int coin : coins) {
//             for (int i = coin; i <= amount; ++i) {
//                 if (dp[i] > INT_MAX - dp[i - coin])
//                     dp[i] = INT_MAX;
//                 else
//                     dp[i] += dp[i - coin];
//             }
//         }
//         return dp[amount];
//     }
// };
