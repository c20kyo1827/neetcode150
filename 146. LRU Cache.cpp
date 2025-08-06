class LRUCache {
    int _capacity;
    // pair<key, value> -> key is for evicting
    std::list<std::pair<int, int>> linkedList; // Double-linked list
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> hashMap;
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        auto iter = hashMap.find(key);
        if (iter == hashMap.end())
            return -1;
        linkedList.splice(linkedList.begin(), linkedList, iter->second);
        return iter->second->second;
    }
    
    void put(int key, int value) {
        auto iter = hashMap.find(key);
        if (iter != hashMap.end())
            linkedList.erase(iter->second);
        linkedList.push_front({key, value});
        hashMap[key] = linkedList.begin();
        if(hashMap.size() > _capacity) {
            auto erasedKey = linkedList.rbegin()->first;
            linkedList.pop_back();
            hashMap.erase(erasedKey);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
