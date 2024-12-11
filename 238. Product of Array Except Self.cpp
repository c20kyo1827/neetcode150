// /*
//     [a,b,c,d]
//     [0] : 1     | b*c*d
//     [1] : a     | c*d
//     [2] : a*b   | d
//     [3] : a*b*c | 1
// */
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int size = nums.size();
//         vector<int> ans(size, 0);
//         vector<int> temp1(size, 1);
//         vector<int> temp2(size, 1);
//         for(int i=0 ; i<size ; i++){
//             if(i-1 >= 0){
//                 temp1[i] = temp1[i-1] * nums[i-1];
//             }

//             if(size-i < size){
//                 temp2[size-i-1] = temp2[size-i] * nums[size-i];
//             }
//         }
//         for(int i=0 ; i<size ; i++){
//             ans[i] = temp1[i] * temp2[i];
//         }
//         // cout << "temp1\n";
//         // for(auto a: temp1){
//         //     cout << a << "\n";
//         // }
//         // cout << "temp2\n";
//         // for(auto a: temp2){
//         //     cout << a << "\n";
//         // }
//         return ans;
//     }
// };

/*
    [a,b,c,d]

    [0] : 1     
    [1] : a     
    [2] : a*b   
    [3] : a*b*c 

    [0] : 1     <- d*c*b
    [1] : a     <- d*c
    [2] : a*b   <- d
    [3] : a*b*c <- 1
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size, 1);
        for(int i=0 ; i<size ; i++){
            if(i-1 >= 0){
                ans[i] = ans[i-1] * nums[i-1];
            }
        }
        int product = 1;
        for(int i=0 ; i<size ; i++){
            if(size-i < size){
                product = product * nums[size-i];
                ans[size-i-1] = ans[size-i-1] * product;
            }
        }
        return ans;
    }
};
