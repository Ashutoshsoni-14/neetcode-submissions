class LRUCache {
   public:
    list<int> dll;
    unordered_map<int, pair<list<int>::iterator, int>> mp;
    int n;
    LRUCache(int capacity) { n = capacity; }

    void makeItRecentlyUsed(int key) {
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        makeItRecentlyUsed(key);
        return mp[key].second;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key].second = value;
            makeItRecentlyUsed(key);
        } else {
            dll.push_front(key);
            mp[key].first = dll.begin();
            mp[key].second = value;
            n--;
        }
        if (n < 0) {
            int keyToBeDeleted = dll.back();
            mp.erase(keyToBeDeleted);
            dll.pop_back();
            n++;
        }
    }
};
