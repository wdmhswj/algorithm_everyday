#include <iostream>
#include <vector>

int direct[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

void dfs(const std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& visited, int x, int y)
{   

    for(int i=0; i<4; i++)
    {
        int next_x=x+direct[i][0];
        int next_y=y+direct[i][1];

        // 范围越界
        if (next_x<0 || next_x>=grid.size() || next_y<0 || next_y>=grid[0].size())
            continue;
        
        // 是陆地且没有访问过
        if(grid[next_x][next_y]==1 && !visited[next_x][next_y])
        {
            visited[next_x][next_y]=1;
            dfs(grid, visited, next_x, next_y);
        }
    }
}
int main()
{
    int N=0, M=0;
    std::cin>>N>>M;
    std::vector<std::vector<int>> grid(N, std::vector<int>(M, 0));
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            std::cin>>grid[i][j];
        }
    }

    std::vector<std::vector<int>> visited(N, std::vector<int>(M, 0));
    int num=0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(grid[i][j]==1 && visited[i][j]==0)
            {
                visited[i][j]=1;
                dfs(grid, visited, i, j);
                ++num;
            }
        }
    }
    std::cout<<num;
}