class WordDictionary {
public:
    WordDictionary() {
        ;
    }
    
    void addWord(string word) {
        _wordSet.insert(word);
        _length2wordSet[word.length()].insert(word);
    }
    
    bool search(string word) {
        if (word.find(".") == string::npos)
            return _wordSet.count(word);
        bool isFind = true;
        for (const string& check : _length2wordSet[word.length()]){
            int i = 0; 
            for (i = 0; i < word.length(); ++i) {
                if (word[i] == '.') continue;
                if (word[i] != check[i]) break;
            }
            if(i == word.length()) return true;
        }
        return false;
    }
    unordered_set<string> _wordSet;
    unordered_map<int, unordered_set<string>> _length2wordSet;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
