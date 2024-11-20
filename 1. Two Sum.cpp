class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> table;
        for(int i=0 ; i<nums.size() ; i++){
            if(table.find(nums[i]) != table.end()){
                return {table[nums[i]], i};
            }
            table[target-nums[i]] = i;
        }
        return {0,0};
    }
};
