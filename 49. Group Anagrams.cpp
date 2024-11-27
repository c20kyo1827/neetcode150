// // Sort
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         std::unordered_map<string, int> strToIndex;
//         std::vector<vector<string>> ans;
//         // int count = 0;
//         for(auto& str : strs){
//             string tmp = str; 
//             std::sort(tmp.begin(), tmp.end());
//             if(strToIndex.count(tmp) <= 0){
//                 // strToIndex[tmp] = count;
//                 strToIndex[tmp] = ans.size();
//                 ans.push_back(vector<string>(0));
//             }
//             ans[strToIndex[tmp]].push_back(str);
//         }
//         return ans;
//     }
// };

// Table count
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> tableStrToStrs;
        std::vector<vector<string>> ans;
        for(auto& str : strs){
            string tmp; 
            int table[26] = {0};
            // table
            for(auto chr : str) table[chr-'a']++;
            // create string tmp
            for(int i=0 ; i<26 ; i++){
                if(table[i] == 0) continue;
                tmp += string(1, i+'a') + to_string(table[i]);
            }
            tableStrToStrs[tmp].push_back(str);
        }
        for(auto& [tableStr, strs] : tableStrToStrs)
            ans.push_back(strs);
        return ans;
    }
};
