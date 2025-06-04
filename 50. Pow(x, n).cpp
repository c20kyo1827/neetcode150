// // Recursive
// class Solution {
// public:
//     double myPow(double x, int n) {
//         if (n == 0) return 1;
//         double half = myPow(x, n / 2);
//         if (n % 2 == 0) return half * half;
//         else if (n > 0) return half * half * x;
//         else return half * half / x;
//     }
// };

// Non-recursive
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        // for(int i = abs(n) ; i != 0 ; i /= 2) {
        for(int i = n ; i != 0 ; i /= 2) {
            if (i%2 != 0) res *= x;
            x *= x;
        }
        
32 16 8 4 2 1
        // // bit operation
        // while (n > 0) { 
        //     if (n & 1) {
        //         res *= x;
        //     }
        //     x *= x;
        //     n >>= 1;
        // }
        return n < 0 ? 1 / res : res;
    }
};
