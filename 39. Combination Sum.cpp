// Backtracking
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        std::sort(candidates.begin(), candidates.end());
        for(int i=0 ; i<candidates.size() ; i++){
            if(candidates[i] > target) break;
            if(candidates[i] == target){
                res.push_back({target});
                break;
            }
            auto newCandidates = vector<int>(candidates.begin()+i, candidates.end());
            for(auto cand : combinationSum(newCandidates, target-candidates[i])){
                cand.insert(cand.begin(), candidates[i]);
                res.push_back(cand);
            }
        }
        return res;
    }
};
// // DP
// class Solution {
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector< vector< vector<int> > > dp;
//         dp.resize(target+1, vector< vector<int> > ());
//         std::sort(candidates.begin(), candidates.end());
        
//         for(int subTarget=1 ; subTarget<=target ; subTarget++){
//             for(auto& num : candidates){
//                 if(num > subTarget) break;
//                 if(num == subTarget){
//                     dp[subTarget].push_back({num});
//                     break;
//                 }
//                 for(auto subCandidates : dp[subTarget - num]){
//                     if(num > subCandidates[0]) continue;
//                     subCandidates.insert(subCandidates.begin(), num);
//                     dp[subTarget].push_back(subCandidates);
//                 }
//             }
//         }
//         return dp[target];
//     }
// };
