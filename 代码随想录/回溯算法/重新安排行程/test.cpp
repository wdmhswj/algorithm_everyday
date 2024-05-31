#include <map>
#include <unordered_map>
#include <utility>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
private:
    bool backtracking(int ticketNum, vector<string>& result, std::unordered_map<string, std::map<string, int>>& targets){
        if (result.size() == ticketNum+1) {
            return true;
        }
        for (std::pair<const string, int>& target : targets[result[result.size()-1]]) {
            if (target.second>0) {
                result.push_back(target.first);
                target.second--;
                if (backtracking(ticketNum, result, targets)) {
                    return true;
                }
                target.second++;
                result.pop_back();
            }
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        if(tickets.empty()){
            return {};
        }
        std::unordered_map<string, std::map<string, int>> targets;
        vector<string> result;
        for (const vector<string>& vec : tickets) {
            targets[vec[0]][vec[1]]++;  // 记录映射关系
        }
        result.push_back("JFK");
        backtracking(tickets.size(), result, targets);
        return result;
    }
};