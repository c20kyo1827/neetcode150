class Trie {
public:
    bool _isWord;
    Trie* _child[26];
    Trie() {
        _isWord = false;
        for(int i = 0; i < 26; i++)
            this->_child[i] = NULL;
    }
    
    void insert(string word) {
        if(word.empty()) return;
        Trie* cur = this;
        for(auto ch : word){
            if(!cur->_child[ch - 'a']){
                cur->_child[ch - 'a'] = new Trie();
            }
            cur = cur->_child[ch - 'a'];
        }
        cur->_isWord = true;
    }
    
    bool search(string word) {
        if(word.empty()) return false;
        auto* cur = this;
        for(auto ch : word){
            if(!cur->_child[ch - 'a']) return false;
            cur = cur->_child[ch - 'a'];
        }
        return cur->_isWord;
    }
    
    bool startsWith(string prefix) {
        if(prefix.empty()) return false;
        auto* cur = this;
        for(auto ch : prefix){
            if(!cur->_child[ch - 'a']) return false;
            cur = cur->_child[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
