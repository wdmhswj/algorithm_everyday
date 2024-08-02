#include <vector>
#include <iostream>

int help[4][2] = {
    0, 1,
    1, 0,
    0, -1,
    -1, 0,
};

void dfs(const std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>&  visited, int& record, int x, int y)
{
    ++record;
    // if (record>max_size) {
    //     max_size=record;
    // }
    for(int i=0; i<4; i++)    
    {
        int next_x = x+help[i][0];
        int next_y = y+help[i][1];
        if(next_x<0 || next_x>=grid.size() || next_y<0 || next_y>=grid[0].size())
            continue;
        if(grid[next_x][next_y]==1 && visited[next_x][next_y]==0)
        {
            visited[next_x][next_y]=1;
            dfs(grid, visited,  record, next_x, next_y);
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

    int max_size=0;
    std::vector<std::vector<int>> visited(N, std::vector<int>(M, 0));
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(grid[i][j]==1 && visited[i][j]==0)
            {
                visited[i][j]=1;
                int record = 0;
                dfs(grid, visited, record, i, j);
                if(record>max_size)
                    max_size=record;
            }
        }
    }


    std::cout<<max_size;

    return 0;
}