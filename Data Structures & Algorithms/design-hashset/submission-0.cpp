class MyHashSet {
public:
    vector<vector<int>> v;
    const int size = 1000;

    int hash(int key){
        return key % size;
    }

    MyHashSet() {
        v.resize(size);
    }
    
    void add(int key) {
        int idx = hash(key);
        for(int k : v[idx]){
            if(k == key) return ;
        }
        v[idx].push_back(key);
    }
    
    void remove(int key) {
        int idx = hash(key);
        for(int i = 0 ; i < v[idx].size() ; i++){
            if(v[idx][i] == key){
                v[idx].erase(v[idx].begin()+i);
            }
        }
    }
    
    bool contains(int key) {
        int idx = hash(key);
        for(int k : v[idx]){
            if(k == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */