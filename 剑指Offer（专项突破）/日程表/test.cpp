#include "../../utils/utils.h"


class MyCalendar {
public:
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        auto it = _map.lower_bound(start);  // 第一个大于等于start的区间
        if (it!=_map.end() && it->first<end)
            return false;
        if (it!=_map.begin() && (--it)->second>start)
            return false;
        _map[start] = end;
        return true;
    }

    bool book1(int start, int end) {
        auto it = _map.upper_bound(start);  // 第一个结束时间大于start的时间段
        if (it!=_map.end() && it->second<end)   // 如果开始时间小于end
            return false;
        _map[end] = start;
        return true;
    }
private:
    std::map<int, int> _map;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */