class Solution {
public:
    vector<int> partitionLabels(string s) {
        std::vector<int> res;
        int size = s.size(), start = 0, last = 0;
        unordered_map<char, int> charToLast;
        for(int i=0 ; i<size ; i++)
            charToLast[s[i]] = i;
        for(int i=0 ; i<size ; i++){
            last = std::max(last, charToLast[s[i]]);
            if(i == last) {
                res.push_back(last - start + 1);
                start = i+1;
            }
        }
        return res;
    }
};
