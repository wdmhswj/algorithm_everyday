#include <utility>
#include <vector>
#include <iostream>
#include <queue>

int help[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
};

// 广度优先搜索
void bfs(std::vector<std::vector<int>>& grid, int x, int y)
{
    // 入队列前做标记，出列时处理四周单元格
    grid[x][y] = 2;
    std::queue<std::pair<int, int>> que;
    que.push({x, y});

    while(!que.empty())
    {
        auto pair = que.front(); que.pop();
        for(int i=0; i<4; i++)
        {
            int next_x=pair.first+help[i][0];
            int next_y=pair.second+help[i][1];
            if(next_x<0 || next_x>=grid.size() || next_y<0 || next_y>grid[0].size())
                continue;
            if(grid[next_x][next_y]==1)
            {
                grid[next_x][next_y]=2;
                que.push({next_x, next_y});
            }
        }
    }
}

// 深度优先搜索
void dfs(std::vector<std::vector<int>>& grid, int x, int y)
{
    grid[x][y]=2;
    for(int i=0; i<4; i++)
        {
            int next_x=x+help[i][0];
            int next_y=y+help[i][1];
            if(next_x<0 || next_x>=grid.size() || next_y<0 || next_y>grid[0].size())
                continue;
            if(grid[next_x][next_y]==1)
            {
                dfs(grid, next_x, next_y);
            }
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
    for(int j=0; j<M; j++)
    {
        if(grid[0][j]==1)
            bfs(grid, 0, j);
    }
    
    for(int j=0; j<M; j++)
    {
        if(grid[N-1][j]==1)
            bfs(grid, N-1, j);
    }

    for(int i=1; i<N-1; i++)
    {
        if(grid[i][0]==1)
            bfs(grid, i, 0);
    }

    for(int i=1; i<N-1; i++)
    {
        if(grid[i][M-1]==1)
            bfs(grid, i, M-1);
    }

    for(auto& vec: grid)
    {
        for(auto& e: vec)
        {
            if(e==2)    e=1;    // 恢复陆地标记
            else if(e==1)   e=0;    // 将孤岛陆地变为海洋
        }
    }
    for(auto& vec: grid)
    {
        for(auto& e: vec)
        {
            std::cout<<e<<" ";
        }
        std::cout<<std::endl;
    }

    
    return 0;
}