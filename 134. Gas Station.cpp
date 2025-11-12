// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int total = 0, start = 0, sum = 0;
//         for(int i=0 ; i<gas.size() ; i++) {
//             auto gain = gas[i] - cost[i];
//             total += gain;
//             sum += gain;
//             if(sum < 0) {
//                 start = i+1;
//                 sum = 0;
//             }
//         }
//         return total < 0 ? -1 : start;
//     }
// };

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, mx = -1, start = 0;
        for (int i = gas.size() - 1; i >= 0; --i) {
            total += gas[i] - cost[i];
            if (total > mx) {
                start = i;
                mx = total;
            }
        }
        return (total < 0) ? -1 : start;
    }
};
