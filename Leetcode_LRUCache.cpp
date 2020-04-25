class LRUCache {
  int capacity;
  list<int> LRU;
  unordered_map<int, pair<list<int>::iterator, int> > keyToList;

public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
      auto it = keyToList.find(key);
      if(it == keyToList.end()) {
        return -1;
      }
      
      LRU.erase(it->second.first);
      int value = it->second.second;
      
      LRU.push_front(key);
      keyToList[key] = make_pair(LRU.begin(), value);
      
      return value;
    }
    
    void put(int key, int value) {
      auto it = keyToList.find(key);
      if(it == keyToList.end()) {
        LRU.push_front(key);
        keyToList[key] = make_pair(LRU.begin(), value);
        if((int)LRU.size() > capacity) {
          auto last = LRU.end();  last--;
          keyToList.erase(*last);
          LRU.pop_back();
        }
      } else {
        LRU.erase(it->second.first);
        LRU.push_front(key);
        keyToList[key] = make_pair(LRU.begin(), value);
      }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
