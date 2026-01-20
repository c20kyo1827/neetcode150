// // Build jump mapping
// class Solution {
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         std::unordered_map<string, vector<string>> hmap;
//         std::unordered_map<string, bool> visited;
        
//         for(const auto& word: wordList) {
//             visited[word] = false;
//             for(int i = 0; i < word.size(); ++i) {
//                 string newWord = word.substr(0, i) + "*" + word.substr(i+1, word.size()-i-1); 
//                 if(hmap.count(newWord)) {
//                     hmap[newWord].emplace_back(word);
//                 } else {
//                     hmap[newWord] = vector<string>{word};
//                 }
//             }
//         }

//         std::queue<pair<string, int>> q;
//         q.push(pair<string, int>{beginWord, 1});
//         while(!q.empty()) {
//             string word = q.front().first; 
//             int level = q.front().second;
//             q.pop();
            
//             for(int i = 0; i < word.size(); ++i) {
//                 string newWord = word.substr(0, i) + "*" + word.substr(i+1, word.size()-i-1); 
//                 if(hmap.count(newWord)) {
//                     for(const auto& nextWord: hmap[newWord]) {
//                         if(nextWord == endWord) {
//                             return level + 1;
//                         } else if(!visited[nextWord]) {
//                             visited[nextWord] = true;
//                             q.push(pair<string, int>{nextWord, level+1});
//                         }
//                     }
//                 }
//             }
//         }
//         return 0;
//     }
// };

// class Solution {
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         std::unordered_set<string> wordSet(wordList.begin(), wordList.end());
//         if (!wordSet.count(endWord)) return 0;

//         std::unordered_map<string, int> pathCnt{{{beginWord, 1}}};
//         std::queue<string> q{{beginWord}};
//         while (!q.empty()) {
//             string word = q.front();
//             q.pop();
//             for (int i = 0; i < word.size(); ++i) {
//                 string newWord = word;
//                 for (char ch = 'a'; ch <= 'z'; ++ch) {
//                     newWord[i] = ch;
//                     if (wordSet.count(newWord) && newWord == endWord) return pathCnt[word] + 1;
//                     if (wordSet.count(newWord) && !pathCnt.count(newWord)) {
//                         q.push(newWord);
//                         pathCnt[newWord] = pathCnt[word] + 1;
//                     }   
//                 }
//             }
//         }
//         return 0;
//     }
// };

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;
        queue<string> q{{beginWord}};
        int res = 0;
        while (!q.empty()) {
            for (int k = q.size(); k > 0; --k) {
                string word = q.front(); q.pop();
                if (word == endWord) return res + 1;
                for (int i = 0; i < word.size(); ++i) {
                    string newWord = word;
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        newWord[i] = ch;
                        if (wordSet.count(newWord) && newWord != word) {
                            q.push(newWord);
                            wordSet.erase(newWord);
                        }   
                    }
                }
            }
            ++res;
        }
        return 0;
    }
};
