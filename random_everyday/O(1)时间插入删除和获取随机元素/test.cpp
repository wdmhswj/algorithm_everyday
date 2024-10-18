#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <ctime>


class RandomizedSet {
private:
    std::vector<int> nums;
    std::unordered_map<int, int> hash;

public:
    RandomizedSet() {
        // 用当前时间作为种子初始化随机数生成器
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
    }
    
    bool insert(int val) {
        // 查看哈希表，看是否已经有了
        if(hash.count(val)) 
            return false;
        // 在变长数组最后加上此元素
        nums.push_back(val);
        hash[val]=nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        // 查看是否存在
        if(!(hash.count(val)))
            return false;
        // 将最后一个元素插入到要删除的元素的位置
        int last = nums[nums.size()-1];
        int index = hash[val];
        nums[index] = last;
        nums.pop_back();
        // 更新哈希表
        hash[last] = index;
        hash.erase(val);
        
        return true;
    }
    
    int getRandom() {
        return nums[std::rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */