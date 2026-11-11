/*
    index : 0 1       2           n         n+1
    value : 1 nums[0] nums[1] ... nums[n-1] 1
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        // dp[1][5] --> the index 0~4 ballons are burst
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int len = 1; len <= n; ++len) {
            for (int i = 1; i <= n - len + 1; ++i) {
                int j = i + len - 1;
                // k-th balloon is the last one
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = max(dp[i][j],
                        nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j]);
                    /*
                        i~k-1 --> are already burst
                        k+1~j --> are already burst
                    */
                    // cout << len << " " << i << " " << j << " " << k << "\n";
                }
            }
        }
        return dp[1][n];
    }
};
