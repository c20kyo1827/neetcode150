class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        std::vector<std::set<int>> idxToSet(3, std::set<int>());
        for(auto& triplet : triplets){
            bool check = true;
            for(int i=0 ; i<triplet.size() ; i++){
                if(triplet[i] > target[i]){
                    check = false;
                    break;
                }
            }
            if(!check)
                continue;
            for(int i=0 ; i<triplet.size() ; i++){
                idxToSet[i].insert(triplet[i]);
            }
        }
        for(int i=0 ; i<target.size() ; i++){
            if(idxToSet[i].count(target[i]) == 0){
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int c0 = 0, c1 = 0, c2 = 0;

        for(auto &t : triplets){
            if(t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]){
                c0 = max(c0, t[0]);
                c1 = max(c1, t[1]);
                c2 = max(c2, t[2]);
            }
        }

        return (c0 == target[0]) && (c1 == target[1]) && (c2 == target[2]);
    }
};
