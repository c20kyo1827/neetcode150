// class Solution {
// public:
//     vector<int> countBits(int n) {
//         std::vector<int> ans(n+1,0);
//         for(int i=0 ; i<=n ; i++){
//             ans[i] = hammingWeight(i);
//         }
//         return ans;
//     }

//     int hammingWeight(uint32_t n) {
//         int count=0;
//         while(n!=0){
//             if(n%2 == 1)
//                 count++;
//             n = n>>1;
//         }
//         return count;
//     }
// };
class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0) return std::vector<int>{0};
        std::vector<int> ans(n+1,0);
        ans[0] = 0;
        ans[1] = 1;
        for(int i=2 ; i<=n ; i++){
            ans[i] = ans[i/2] + ans[i%2];
        }
        return ans;
    }
};
