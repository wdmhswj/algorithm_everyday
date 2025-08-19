#include "../../utils/utils.h"

class Solution {
public:
    // 直接排序：O(nlogn), O(logn)
    std::vector<int> inventoryManagement(std::vector<int>& stock, int cnt) {
        std::sort(stock.begin(), stock.end());
        return {stock.begin(), stock.begin()+cnt};
    }

    // 优先队列（大根堆）：O(nlogk), O(k)
    std::vector<int> inventoryManagement1(std::vector<int>& stock, int cnt) {
        std::priority_queue<int> pq;
        for (const int& e: stock) {
            pq.push(e);
            if (pq.size()>cnt) {
                pq.pop();
            }
        }
        std::vector<int> rt(cnt, 0);
        for (int i=0; i<cnt; ++i) {
            rt[i] = pq.top();
            pq.pop();
        }
        return rt;
    }

    // 快排：O(n), O(logn)
    std::vector<int> inventoryManagement2(std::vector<int>& stock, int cnt) {
        const int n = stock.size();

        std::function<std::vector<int>(int, int)> sort = [&](int l, int r) -> std::vector<int> {
            int i=l, j=r;
            int pivot = stock[r];
            while (i<j) {
                while (i<j && stock[i]<=pivot) {
                    ++i;
                }
                while (i<j && stock[j]>=pivot) {
                    --j;
                }
                std::swap(stock[i], stock[j]);
            }
            std::swap(stock[i], stock[r]);
            if (i<cnt) {
                sort(i+1, r);
            }
            if (i>cnt) {
                sort(l, i-1);
            }
            return {stock.begin(), stock.begin()+cnt};
        };
        return cnt==n ? stock : sort(0, n-1);
    }
};