class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Sort method
        // std::sort(nums.begin(), nums.end());
        // for(int i=0 ; i<nums.size() ; i++){
        //     if(i != nums[i]) return i;
        // }
        // return nums.size();

        // // XOR
        // int ans = nums.size();
        // for(int i=0 ; i<nums.size() ; i++){
        //     ans ^= i;
        //     ans ^= nums[i];
        // }
        // return ans;

        // Trapezoid formula method
        int tf = (0 + nums.size())*(nums.size()+1)/2;
        for(auto num : nums){
            tf -= num;
        }
        return tf;
    }
};
