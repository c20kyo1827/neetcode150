// binary search
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int left = 1, right = nums.size();
//         while(left < right){
//             int mid = left + (right - left)/2;
//             int cnt = 0;
//             for(auto num : nums){
//                 if(num <= mid)
//                     cnt++;
//             }
//             if (cnt <= mid)
//                 left = mid+1;
//             else
//                 right = mid;
//         }
//         return right;
//     }
// };

// // circular + two pointer
// // https://www.youtube.com/watch?v=SKYy2rphVGk&ab_channel=%E7%96%91%E8%B9%A4%E6%AA%94%E6%A1%88%E5%AE%A4
// // The Cell Probe Complexity of Succinct Data Structures
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int slow = 0;
//         int fast = 0;
//         int temp = 0;
//         while(1) {
//             slow = nums[slow];
//             fast = nums[nums[fast]];
//             if (slow == fast)
//                 break;
//         }

//         while(1) {
//             slow = nums[slow];
//             temp = nums[temp];
//             if (slow == temp)
//                 break;
//         }
//         return slow;
//     }
// };

// bit operation
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < 32; ++i) {
            int bit = (1 << i), cnt1 = 0, cnt2 = 0;
            for (int k = 0; k < n; ++k) {
                if ((k & bit) > 0) ++cnt1;
                if ((nums[k] & bit) > 0) ++cnt2;
            }
            if (cnt2 > cnt1) res += bit;
        }
        return res;
    }
};
