#include <queue>
#include <utility>
#include <vector>
#include <iostream>

const int help[8][2] = {
    {2, -1},
    {1, -2},
    {-1, -2},
    {-2, -1},
    {-2, 1},
    {-1, 2},
    {1, 2},
    {2, 1},
};

int bfs(const std::vector<int>& pos, int size=1000) {
    // 棋盘，同时int值记录步数
    std::vector<std::vector<int>> board(size+1, std::vector<int>(size+1, -1));
    
    std::queue<std::pair<int, int>> que;
    que.push({pos[0], pos[1]});
    board[pos[0]][pos[1]] = 0;
    while(!que.empty())
    {
        auto pair = que.front();
        que.pop();
        if(pair.first == pos[2] && pair.second == pos[3])
            return board[pos[2]][pos[3]];
        for(int i=0; i<8; ++i)
        {
            int x = pair.first + help[i][0];
            int y = pair.second + help[i][1];
            if (x<1 || y<1 || x>size || y>size) {   // 越界
                continue;
            }
            if(board[x][y]==-1){
                board[x][y] = board[pair.first][pair.second] + 1;
                que.push({x, y});
            }
        }
    }
    return -1;
}
int main(){
    int n = 0;
    std::cin>>n;
    std::vector<std::vector<int>> pos(n, std::vector<int>(4, 0));
    for(int i=0; i<n; ++i)
    {
        std::cin>>pos[i][0]>>pos[i][1]>>pos[i][2]>>pos[i][3];
    }
    for(int i=0; i<n; ++i)
    {
        std::cout<<bfs(pos[i])<<std::endl;
    }


    return 0;
}