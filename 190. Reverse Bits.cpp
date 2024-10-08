// class Solution {
// public:
//     uint32_t reverseBits(uint32_t n) {
//         uint32_t ans = 0;
//         for(int i=0 ; i<32 ; i++){
//             ans = ans << 1;
//             ans |= (n >> i) & 1;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t a=0;
        for(int i=0 ; i<32 ; i++){
            a = a*2 + n%2;
            n = n>>1;
        }
        return a;    
    }
};
