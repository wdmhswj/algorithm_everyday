#include "../../utils/utils.h"

struct TwoWaysListNode {
int _value;
int _key;
TwoWaysListNode* _prev;
TwoWaysListNode* _next;

TwoWaysListNode(): _value(0), _prev(nullptr), _next(nullptr) {    
}

TwoWaysListNode(int value, int key): _value(value), _key(key), _prev(nullptr), _next(nullptr) {    
}
TwoWaysListNode(int value, TwoWaysListNode* p, TwoWaysListNode* n): _value(0), _key(0), _prev(p), _next(n) {    
}
};

class LRUCache {
public:
    LRUCache(int capacity): _capacity(capacity), _size(0) {
        _head._next = &_tail;
        _tail._prev = &_head;
    }
    
    int get(int key) {
        if (!_map.count(key)) return -1;
        int ret_value = _map[key]->_value;
        moveNode2Head(_map[key]);
        return ret_value;
    }
    
    void put(int key, int value) {
        if (_map.count(key)) {
            TwoWaysListNode* node = _map[key];
            node->_value = value;
            moveNode2Head(node);
        } else {
            TwoWaysListNode* node = new TwoWaysListNode(value, key);
            addNode2Head(node);
            _map[key] = node;
            ++_size;
            if (_size>_capacity) {
                int remove_key = _tail._prev->_key;
                removeTail();
                _map.erase(remove_key);
                --_size;
            }
        }
    }

private:
    // 删除节点
    void removeNode(TwoWaysListNode* node) {
        node->_prev->_next = node->_next;
        node->_next->_prev = node->_prev;
        delete node;
    }
    // 在头部插入节点
    void addNode2Head(TwoWaysListNode* node) {
        node->_next = _head._next;
        node->_prev = &_head;
        _head._next = node;
        node->_next->_prev = node;
    }
    // 将节点移到头部：删除节点+在头部插入节点
    void moveNode2Head(TwoWaysListNode* node) {
        node->_prev->_next = node->_next;
        node->_next->_prev = node->_prev;

        addNode2Head(node);
    }
    // 删除尾部节点
    void removeTail() {
        removeNode(_tail._prev);
    }
private:
    int _capacity;
    int _size;
    std::unordered_map<int, TwoWaysListNode*> _map;  // <key, Node*>
    TwoWaysListNode _head;
    TwoWaysListNode _tail;


};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */