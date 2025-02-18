// // Hash
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         std::unordered_map<int, int> table;
//         for(int i=0 ; i<nums.size() ; i++){
//             if(table.find(nums[i]) != table.end()){
//                 return {table[nums[i]]+1, i+1};
//             }
//             table[target-nums[i]] = i;
//         }
//         return {1,2};
//     }
// };

// Two pointer
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum == target)
                return {left+1,right+1};
            else if(sum > target)
                right--;
            else if(sum < target)
                left++;
        }
        return {1,2};
    }
};
