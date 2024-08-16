#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

int help[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
};

void dfs(std::vector<std::vector<int>>& grid, int& count, int mark, int x, int y)
{
    if(grid[x][y]!=1)
        return;
    ++count;
    grid[x][y]=mark;

    for(int i=0; i<4; i++)
    {
        int new_x=x+help[i][0];
        int new_y=y+help[i][1];
        if(new_x<0||new_y<0||new_x>=grid.size()||new_y>=grid[0].size())
            continue;
        dfs(grid, count, mark, new_x, new_y);
    }


}

int main()
{
    int N=0, M=0;
    std::cin>>N>>M;
    
    std::vector<std::vector<int>> grid(N, std::vector<int>(M, 0));
    for(auto& vec: grid)
    {
        for(auto& e: vec)
        {
            std::cin>>e;
        }
    }

    // 记录并标记岛屿
    int mark=2;                     // 从2开始与陆地的1作区别
    std::unordered_map<int, int> map;
    bool isAllLand = true;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(grid[i][j]==0)
                isAllLand=false;
            if(grid[i][j]==1)
            {
                int count=0;
                dfs(grid, count, mark, i, j);
                map[mark]=count;
                ++mark;
            }
        }
    }
    
    // 全都为陆地
    if(isAllLand)
    {
        std::cout<<N*M;
        return 0;
    }
    // 遍历海洋
    int max=0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(grid[i][j]==0)
            {
                int size=1;
                std::unordered_set<int> visitedIsland;
                for(int k=0; k<4; k++)
                {
                    int new_x=i+help[k][0];
                    int new_y=j+help[k][1];
                    if(new_x<0||new_y<0||new_x>=grid.size()||new_y>=grid[0].size()) // 越界
                        continue;
                    if(visitedIsland.find(grid[new_x][new_y])!=visitedIsland.end()) // 已经放过该岛屿
                        continue;
                    size += map[grid[new_x][new_y]];
                    visitedIsland.insert(grid[new_x][new_y]);
                    
                }
                max = std::max(max, size);
            }
        }
    }

    std::cout<<max;
    return 0;
}