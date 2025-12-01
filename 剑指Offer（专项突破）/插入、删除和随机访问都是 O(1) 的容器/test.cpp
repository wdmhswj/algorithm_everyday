#include "../../utils/utils.h"

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        // 判断是否已经存在
        if (_map.count(val))
            return false;
        _map[val] = _array.size();
        _array.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        // 判断是否存在
        if (!_map.count(val))
            return false;
        // 将数组中要删除的元素替换为数组最后一个元素，避免大规模移动数组元素
        int removeIndex = _map[val];
        _array[removeIndex] = _array.back();
        _map[_array.back()] = removeIndex;
        _array.pop_back();
        _map.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return _array[rand()%_array.size()];
    }

private:
    std::unordered_map<int, int> _map;
    std::vector<int> _array;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */