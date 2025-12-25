#include "../../utils/utils.h"

class RecentCounter {
public:
    RecentCounter(): _last_t(-1) {

    }
    
    int ping(int t) {
        if (_map.empty())
        {
            _map[t] = 0;
            _last_t = t;
            return 1;
        }
            
        _map[t] = _map[_last_t] + 1;
        _last_t = t;
        int lb = t-3000;
        auto it = _map.lower_bound(lb);
        if (it!=_map.end() && it->first==lb) {
            return _map[t]-it->second+1;
        } else {
            if (it!=_map.begin()) {
                auto prev_it = std::prev(it);
                return _map[t]-prev_it->second;
            } else {
                return _map[t];
            }
        }       
    }
private:
    std::map<int, int> _map;
    int _last_t;
};

class RecentCounter {
public:
    RecentCounter(): _count(0) {

    }
    
    int ping(int t) {
        _map[t] = ++_count;

        auto lb = _map.lower_bound(t-3000);
        if (lb==_map.begin())
            return _map[t];
        return _map[t] - std::prev(lb)->second;
    }
private:
    std::map<int, int> _map;
    int _count;
};

class RecentCounter {
public:
    RecentCounter() {

    }
    
    int ping(int t) {
        _q.push(t);
        while (!_q.empty() && _q.front()<t-3000) {
            _q.pop();
        }
        return _q.size();

    }
private:
    std::queue<int> _q;
};
/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */