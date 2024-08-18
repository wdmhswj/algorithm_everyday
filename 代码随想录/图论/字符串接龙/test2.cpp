// #include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <string>
#include <queue>


bool isEdge(const std::string& a, const std::string& b)
{
    if(a.size()!=b.size())
        return false;
    int record = 0;
    for(int i=0; i<a.size(); i++)
    {
        if (a[i]!=b[i]) {
            ++record;
            if(record>1)
                break;
        }
        
    }
    // std::cout<<"isEdge: a="<<a<<" b="<<b<<" result="<< (record==1)<<std::endl;
    return record==1;
}


int main()
{   
    int N=0;
    std::cin>>N;
    std::string beginStr, endStr;
    std::cin>>beginStr>>endStr;
    std::vector<std::string> strList(N+2);
    for(int i=0; i<N; i++)
    {
        std::cin>>strList[i];
    }
    strList[N]=beginStr;
    strList[N+1]=endStr;
    std::unordered_map<int, int> visited_map;
    std::queue<int> que;
    que.push(N);
    visited_map.insert(std::pair<int, int>(N, 1));
    while (!que.empty()) {
        int index = que.front();
        que.pop();

        if (isEdge(strList[index], strList[N+1])) {
            std::cout<<visited_map[index]+1;
            return 0;
        }
        for(int i=0; i<N; i++)
        {
            if (visited_map.find(i)==visited_map.end() && isEdge(strList[index], strList[i])) {
                que.push(i);
                visited_map[i]=visited_map[index]+1;
            }
        }
    }
    
    std::cout<<0;
    

    return 0;
}