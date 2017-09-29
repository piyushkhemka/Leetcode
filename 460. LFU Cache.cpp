class LFUCache {

    int n;

    int minfreq;

    // key, value, freq
    unordered_map<int, pair<int, int> > db;

    // key
    unordered_map<int, list<int>::iterator > itcache;

    // freq, list->key
    unordered_map<int, list<int>> cache;

public:
    LFUCache(int capacity) {

        n = capacity;

    }

    int get(int key) {

        auto it = db.find(key);
        auto iter = itcache.find(key);
        if(it == db.end() || iter == itcache.end())
            return -1;

        (it->second.second)++;
        int newfreq = it->second.second;
        int curfreq = newfreq-1;

        cache[curfreq].erase(iter->second);
        cache[newfreq].push_front(key);
        itcache[key] = cache[newfreq].begin();

        if(cache[minfreq].size() == 0)
            minfreq++;

        return it->second.first;


    }

    void put(int key, int value) {

        auto it = db.find(key);
        auto iter = itcache.find(key);
        if(it!=db.end()) {

            (it->second.second)++;
            it->second.first = value;
            int newfreq = it->second.second;
            int curfreq = newfreq-1;
            cache[curfreq].erase(iter->second);
            cache[newfreq].push_front(key);
            itcache[key] = cache[newfreq].begin();
            return;
        }

        if(itcache.size() == n) {

            if(cache[minfreq].size() == 0)
                return;

            int keytodel = cache[minfreq].back();
            cache[minfreq].pop_back();
            itcache.erase(keytodel);
            db.erase(keytodel);

        }

        minfreq = 1;
        db[key] = make_pair(value, 1);
        cache[1].push_front(key);
        itcache[key] = cache[1].begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
