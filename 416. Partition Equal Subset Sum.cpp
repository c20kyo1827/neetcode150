// // DP
// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int sum = accumulate(nums.begin(), nums.end(), 0);
//         int target = sum / 2;
//         if (sum % 2) return false;
//         vector<bool> dp(target + 1, false);
//         dp[0] = true;
//         for (int num : nums) {
//             for (int i = target; i >= num; --i) {
//                 dp[i] = dp[i] || dp[i - num];
//             }
//         }
//         return dp[target];
//     }
// };

// Bitset
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<10001> bits(1); // 200*100/2 + 1
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int num : nums) bits |= bits << num;
        return (sum % 2 == 0) && bits[sum >> 1];
    }
};
