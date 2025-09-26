

class Solution {
public:
    int mechanicalAccumulator(int target) {
        target>0 && (target += mechanicalAccumulator(target-1));
        return target;
    }
};