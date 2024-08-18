#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

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
    std::cout<<"isEdge: a="<<a<<" b="<<b<<" result="<< (record==1)<<std::endl;
    return record==1;
}


void dfs(const std::vector<std::string>& strList, int N, std::vector<int>& visited, int index, int length, int& result)
{
    // ++length;
    // visited[index]=1;   // 正在访问当前节点
    // 判断当前元素是否连接endStr
    if(isEdge(strList[index], strList[N+1]))
    {
        result = std::min(result, length+1);
        return;
    }

    // 查看未访问的str是否可以连接
    for(int i=0; i<N; i++)
    {
        if (visited[i]==0 && isEdge(strList[index], strList[i])) {
            visited[i]=1;
            dfs(strList, N, visited, i, length+1, result);
            visited[i]=0;   // 撤销对该节点的访问
            // --length;
        }
    }
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
    std::vector<int> visited(N, 0);
    int result = 503;
    for(int i=0; i<N; i++)
    {
        if(isEdge(beginStr, strList[i]))    // 与beginStr相连
        {
            // int length = 1;
            visited[i]=1;
            dfs(strList, N, visited, i, 2, result);
            visited[i]=0;
        }
    }
    if(result==503)
        std::cout<<0;
    else std::cout<<result;
    

    return 0;
}