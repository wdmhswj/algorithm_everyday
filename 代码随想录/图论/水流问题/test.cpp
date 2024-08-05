#include <iostream>
#include <vector>

int help[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
};

void dfs(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& visited, int x, int y)
{
    if(visited[x][y]==1)    return;
    visited[x][y] = 1;
    for(int i=0; i<4; i++)
    {
        int next_x = x+help[i][0];
        int next_y = y+help[i][1];
        if (next_x<0 || next_y<0 || next_x>=grid.size() || next_y>=grid[0].size())  
            continue;
        if(grid[x][y]>grid[next_x][next_y]) continue;
        dfs(grid, visited, next_x, next_y);
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

    // 2组标记数组
    std::vector<std::vector<int>> record1(N, std::vector<int>(M, 0));
    std::vector<std::vector<int>> record2(N, std::vector<int>(M, 0));

    for(int j=0; j<M; j++)
    {
        dfs(grid, record1, 0, j);
        dfs(grid, record2, N-1, j);
    }

    for(int j=0; j<N; j++)
    {
        dfs(grid, record1, j, 0);
        dfs(grid, record2, j, M-1);
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(record1[i][j]==1 && record2[i][j]==1)
            {
                std::cout<<i<<" "<<j<<std::endl;
            }
        }
    }
    return 0;
}