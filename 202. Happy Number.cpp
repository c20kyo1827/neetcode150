// Math
// class Solution {
// public:
//     bool isHappy(int n) {
//         // std::unordered_map<int, int> numToHappyValue;
//         std::set<int> unHappyNum;
//         while(n>0) {
//             int sum = 0;
//             while(n>0) {
//                 sum += std::pow(n%10, 2);
//                 n /= 10;
//             }
//             if(sum==1) return true;
//             if(unHappyNum.count(sum)) return false;
//             unHappyNum.insert(sum);
//             n = sum;
//         }
//         return false;
//     }
// };

// Slow, fast pointer
class Solution {
public:
    bool isHappy(int n) {
        int slowSum = n;
        int fastSum = n;
        while(slowSum!=1 || fastSum!=1) {
            slowSum = calcSum(slowSum);
            fastSum = calcSum(calcSum(fastSum));
            if(slowSum==1 || fastSum==1) return true;
            if(slowSum == fastSum) return false;
        }
        return true; // n = 1
    }

    int calcSum(int n){
        int sum = 0;
        while(n>0) {
            sum += std::pow(n%10, 2);
            n /= 10;
        }
        return sum;
    }
};
