// #include <algorithm>
#include <queue>
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

struct knight {
    int g, h ,f;    // 距离
    int x, y;   // 当前节点位置
    bool operator<(const knight& r)  const {   // 重载运算符，需要是const，优先级队列默认是最大堆，所以符号要反转
        return r.f<f;
    }


    // knight(int x, int y, const knight& k, int e_x, int e_y)
    //     : x(x), y(y)
    // {
    //     g = k.g+5;
    //     h = (x-e_x)*(x-e_x) + (y-e_y)*(y-e_y);
    //     f = g + h;
    // }

    // knight(int x, int y, int g, int h, int f)
    //     : x(x), y(y), g(g), h(h), f(f)
    // {}

};



int bfs(const std::vector<int>& pos, std::vector<std::vector<int>>& board, std::priority_queue<knight>& p_q, int size=1000) {
    // 棋盘，同时int值记录步数
    
    
    // std::queue<std::pair<int, int>> que;
    // std::priority_queue<knight> p_q;
    
    // int s_h = (pos[2]-pos[0])*(pos[2]- pos[0]) + (pos[3]-pos[1])*(pos[3]- pos[1]);
    knight s;
    s.x=pos[0];
    s.y=pos[1];
    s.g = 0;
    s.h = (pos[2]-pos[0])*(pos[2]- pos[0]) + (pos[3]-pos[1])*(pos[3]- pos[1]);
    s.f = s.g + s.h;
    p_q.push(s);
    // que.push({pos[0], pos[1]});
    board[pos[0]][pos[1]] = 0;
    while(!p_q.empty())
    {
        auto k = p_q.top();
        p_q.pop();

        if(k.x == pos[2] && k.y == pos[3])
            return board[pos[2]][pos[3]];

        for(int i=0; i<8; ++i)
        {
            int x = k.x + help[i][0];
            int y = k.y + help[i][1];
            if (x<1 || y<1 || x>size || y>size) {   // 越界
                continue;
            }
            if(board[x][y]==-1){
                board[x][y] = board[k.x][k.y] + 1;
                // p_q.emplace(x, y, k, pos[2], pos[3]);

                knight s;
                s.x=x;
                s.y=y;
                s.g = k.g+5;
                s.h = (pos[2]-x)*(pos[2]- x) + (pos[3]-y)*(pos[3]- y);
                s.f = s.g + s.h;
                p_q.push(s);

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
    
    



    return 0;
}