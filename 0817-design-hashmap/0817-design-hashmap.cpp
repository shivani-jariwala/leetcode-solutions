class MyHashMap {
private: 
    int tableSize = 10007;
    vector<list<pair<int,int>>> table;
    int hash(int key){
        return key%tableSize;
    }
public:
    MyHashMap() {
        table.resize(tableSize);
    }
    
    void put(int key, int value) {
        int index = hash(key);
        auto& bucket = table[index];
        for(auto& it : bucket) {
            if(it.first==key){
                it.second =value;
                return;
            }
        }
        bucket.push_back({key,value});
    }
    
    int get(int key) {
        int index= hash(key);
        const auto& bucket = table[index];
        for(const auto& it: bucket) {
            if(it.first == key){
                return it.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = hash(key);
        auto& bucket = table[idx];
        for(auto it=bucket.begin(); it!=bucket.end();){
            if(it->first == key) {
                //erase
                it= bucket.erase(it);
            }else{
                it++;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */