class LRUCache {
    int _capacity;
    int _size;
    list<pair<int, int>> _cache;
    unordered_map<int, list<pair<int, int>>::iterator> _map;
public:
    LRUCache(int capacity): _capacity(capacity), _size(0) {}
    
    int get(int key) {
        if (_map.find(key) == _map.end()) return -1;
        int val = _map[key]->second;
        _cache.erase(_map[key]);
        _map[key] = _cache.insert(_cache.end(), make_pair(key, val));
        return val;
    }
    
    void put(int key, int value) {
        if (_map.find(key) == _map.end()) {
            if (_size == _capacity) {
                _size--;
                _map.erase(_cache.begin()->first);
                _cache.pop_front();
            }
            _size++;
            _map[key] = _cache.insert(_cache.end(), make_pair(key, value));
        } else {
            _cache.erase(_map[key]);
            _map[key] = _cache.insert(_cache.end(), make_pair(key, value));
        }
    }
};