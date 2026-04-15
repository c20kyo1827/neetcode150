class Trie {
public:
  string* _word; // Change to string::word
  Trie *_child[26];
  Trie() {
    _word = nullptr;
    for (int i = 0; i < 26; i++)
      this->_child[i] = NULL;
  }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(words.empty() || board.empty()) return words;
        Trie* root = new Trie();
        for(auto& word : words){
          Trie *cur = root;
          for (auto ch : word) {
            if (!cur->_child[ch - 'a']) cur->_child[ch - 'a'] = new Trie();
            cur = cur->_child[ch - 'a'];
          }
          cur->_word = &word;
        }
        const auto row = board.size();
        const auto col = board[0].size();
        set<string> ans;
        // auto walk = [&](int x, int y, Trie* cur, string find) {
        function<void(int, int, Trie*)> walk = [&](int x, int y, Trie* cur) {  
          if(x<0 || x>=col || y<0 || y>=row || board[y][x]=='*') return;
          const auto ch = board[y][x];
          Trie* next = cur->_child[ch-'a'];
          if(!next) return;
          if(next->_word != nullptr){
            ans.insert(*next->_word);
            next->_word = nullptr;
          }
          board[y][x] = '*';
          walk(x+1, y, next);
          walk(x-1, y, next);
          walk(x, y+1, next);
          walk(x, y-1, next);
          board[y][x] = ch;
        };

        for (int i=0 ; i<row; i++)
          for (int j=0 ; j<col; j++)
            walk(j, i, root);
        vector<string> ans_vec;
        for(auto word : ans){
          ans_vec.push_back(word);
        }
        return ans_vec;
    }
};
