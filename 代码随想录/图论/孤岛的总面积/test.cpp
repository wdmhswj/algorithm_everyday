#include <utility>
#include <vector>
#include <iostream>
#include <queue>

int help[4][2] = {
    0, 1,
    1, 0,
    0, -1,
    -1, 0,
};

bool bfs(const std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>&  visited, int& record, int x, int y)
{   
    // 是否为孤岛
    bool isIsolatedIsland = true;

    // 当前节点为陆地，面积加1
    ++record;

    // bfs用的队列
    std::queue<std::pair<int, int>> que;

    // 首个元素入栈
    que.push({x, y});

    // bfs的遍历
    while(!que.empty())
    {
        auto pair = que.front();    que.pop();
        for(int i=0; i<4; i++)    
        {
            int next_x = pair.first+help[i][0];
            int next_y = pair.second+help[i][1];

            // 如果当前位置的四周位置为越界位置，则当前岛屿不是孤岛
            if(next_x<0 || next_x>=grid.size() || next_y<0 || next_y>=grid[0].size())
            {
                isIsolatedIsland = false;
                continue;
            }
            if(grid[next_x][next_y]==1 && visited[next_x][next_y]==0)
            {
                visited[next_x][next_y]=1;
                ++record;
                // 访问后要入栈，之后继续访问周围区域
                que.push({next_x, next_y});
            }
        }
    }

    return isIsolatedIsland;

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

    int sum_size=0;
    std::vector<std::vector<int>> visited(N, std::vector<int>(M, 0));
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(grid[i][j]==1 && visited[i][j]==0)
            {
                visited[i][j]=1;
                int record = 0;
                if(bfs(grid, visited,record, i, j))
                    sum_size+=record;
            }
        }
    }


    std::cout<<sum_size;

    return 0;
}