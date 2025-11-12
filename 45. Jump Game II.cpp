// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int size = nums.size();
//         vector<int> dp(size, INT_MAX);
//         dp[0] = 0;
//         for(int i=0 ; i<size ; i++) {
//             for(int j=0 ; j<=nums[i] ; j++) {
//                 if(i+j < size)
//                     dp[i+j] = std::min(dp[i+j], dp[i]+1);
//             }
//         }
//         return dp[size-1];
//     }
// };

// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int res = 0, n = nums.size(), i = 0, cur = 0;
//         while (cur < n - 1) {
//             ++res;
//             int pre = cur;
//             for (; i <= pre; ++i) {
//                 cur = max(cur, i + nums[i]);
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0, n = nums.size(), last = 0, cur = 0;
        for (int i = 0; i < n - 1; ++i) {
            cur = max(cur, i + nums[i]);
            if (i == last) {
                last = cur;
                ++res;
                if (cur >= n - 1) break;
            }
        }
        return res;
    }
};
