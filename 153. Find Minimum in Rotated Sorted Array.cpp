class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums[0] <= nums[nums.size()-1]) return nums[0];
        int left = 0;
        int right = nums.size()-1;
        while(1){
            int med = (left+right)/2;
            if(med == left) break;
            if(nums[left] < nums[med]){
                left = med;
            }
            else{
                right = med;
            }
        }
        return nums[right];
    }
};
