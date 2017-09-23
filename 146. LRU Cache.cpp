class LRUCache {

    int n;
    unordered_map<int, list<pair<int, int>> :: iterator > db;
    list<pair<int,int> > cache;

public:
    LRUCache(int capacity) {
        n = capacity;
    }

    int get(int key) {

        auto it = db.find(key);
        if(it == db.end())
            return -1;

        // erase from list & push in front
        cache.erase(it->second);
        cache.push_front(make_pair(key, it->second->second));
        // erase old key & value. Insert new iterator which is at begin
        //db.erase(key);
        db[key] = cache.begin();

        return it->second->second;

    }

    void put(int key, int value) {

        auto it = db.find(key);
        if(it!=db.end()) {
             // erase from list & push in front
            cache.erase(it->second);
            cache.push_front(make_pair(key, value));

           // db.erase(key);
            db[key] = cache.begin();

            // Need to return here so that don't accidentally do anything else in case capacity = max & key already existed.
            return;
        }

        if(cache.size() == n) {
            int keytodel = cache.back().first;
            cache.pop_back();
            db.erase(keytodel);
        }

        cache.push_front(make_pair(key, value));
        db[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
