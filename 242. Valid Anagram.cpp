// // Sort
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         std::sort(s.begin(), s.end());
//         std::sort(t.begin(), t.end());
//         return s==t;
//     }
// };

// Hash
class Solution {
public:
    bool isAnagram(string s, string t) {
        int table[26] = {0};
        for(auto c : s) table[int(c)-int('a')]++;
        for(auto c : t) table[int(c)-int('a')]--;
        for(auto v : table) if(v!=0) return false;
        return true;
    }
};
