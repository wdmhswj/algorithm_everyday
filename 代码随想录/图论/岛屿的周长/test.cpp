#include <iostream>
#include <vector>

int help[4][2] = {
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0},
};

void dfs(const std::vector<std::vector<int>>& grid, int& perimeter, int x, int y, std::vector<std::vector<int>>& visited)
{
	std::cout<<"x="<<x<<" y="<<y<<std::endl;
	visited[x][y]=1;
	// 判断四周
	for(int i=0; i<4; i++)
	{
		int new_x = x+help[i][0];
		int new_y = y+help[i][1];
		// 位于边缘
		if(new_x<0 || new_y<0 || new_x>=grid.size() || new_y>=grid[0].size())
		{
			++perimeter;
			continue;
		}
		// 判断是否已经访问过
		if(visited[new_x][new_y]==1)
		{
			continue;
		}
		// 判断是否是海洋
		if(grid[new_x][new_y]==0)
		{
			++perimeter;
		}else{
			dfs(grid, perimeter, new_x, new_y, visited);
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

	int perimeter = 0;
	std::vector<std::vector<int>> visited(N, std::vector<int>(M, 0));
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			std::cout<<grid[i][j]<<" ";
			if(grid[i][j]==1)
			{
				dfs(grid, perimeter, i, j, visited);
				std::cout<<perimeter;
				return 0;
			}
		}
	}
	return 0;

}