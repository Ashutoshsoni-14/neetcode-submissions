class MyHashMap {
public:
    vector<vector<pair<int,int>>> v;
    const int size = 1000;

    int hash(int key){
        return key%size;
    }

    MyHashMap() {
        v.resize(size);
    }
    
    void put(int key, int value) {
        int idx = hash(key);
        for(auto & i : v[idx]){
            if(i.first == key){
                i.second = value;
                return ;
            }
        }
        v[idx].push_back({key , value});
    }
    
    int get(int key) {
        int idx = hash(key);
        for(auto & i : v[idx]){
            if(i.first == key){
                return i.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = hash(key);
        int ptr = 0;
        for(auto & i : v[idx]){
            if(i.first == key){
                v[idx].erase(v[idx].begin()+ptr);
            }
            ptr++;
        }
    }
};
