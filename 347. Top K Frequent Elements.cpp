// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> valToCount;
//         priority_queue<pair<int, int>> countPriorityQueue;
//         vector<int> ans;
//         for(auto& num : nums){
//             ++valToCount[num];
//         }
//         for(auto iter : valToCount){
//             countPriorityQueue.push({iter.second, iter.first});
//         }
//         for(int i=0 ; i<k ; i++){
//             ans.push_back(countPriorityQueue.top().second);
//             countPriorityQueue.pop();
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> valToCount;
        vector<vector<int>> bucketCountToVal(nums.size()+1);
        vector<int> ans;
        for(auto& num : nums){
            ++valToCount[num];
        }
        for(auto iter : valToCount){
            bucketCountToVal[iter.second].push_back(iter.first);
        }

        for(int i=nums.size() ; i>=0 ; i--){
            for(auto val : bucketCountToVal[i]){
                ans.push_back(val);
            }
            if(ans.size() == k) break;
        }
        return ans;
    }
};
