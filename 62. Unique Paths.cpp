/*
Fail 
runtime error: signed integer overflow: 479001600 * 13 cannot be represented in type 'int'
*/
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         return frac(m+n-2)/frac(m-1)/frac(n-1);
//     }
//     int frac(int n){
//         int frac = 1;
//         for(int i = 1; i <= n; ++i) {
//             frac *= i;
//         }
//         return frac;
//     }
// };
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         int ans = 1;
//         int down = 0;
//         int right = 0;
//         for(int i=1 ; i<m ; i++){
//             ans = ans * (down+right+1) / (down+1);
//             down++;
//         }
//         for(int i=1 ; i<n ; i++){
//             ans = ans * (down+right+1) / (right+1);
//             right++;
//         }
//         return ans;
//     }
// };

// // DP -> can be optimized with 1-D vector
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1));
//         for (int i = 1; i < m; ++i) {
//             for (int j = 1; j < n; ++j) {
//                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; 
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };

// n!/k!(n-k)!
class Solution {
public:
    int uniquePaths(int m, int n) {
        double num = 1, denom = 1;
        int small = m > n ? n : m;
        for (int i = 1; i <= small - 1; ++i) {
            num *= m + n - 1 - i;
            denom *= i;
        }
        return (int)(num / denom);
    }
};
