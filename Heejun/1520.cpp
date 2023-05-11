//1520 내리막 길
#include <iostream>
#include <queue>
using namespace std;

int map[500][500] = {0};
int cost[500][500] = {0};
bool visit[500][500] = {false};
int row, col, result = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

struct node
{
    int x, y, floor;
};

struct cmp
{
    bool operator ()(const node& a, const node& b)
    {
        return a.floor < b.floor;
    }
};

int main()
{
    cin >> row >> col;

    for(int i = 0; i < row; i++) for(int j = 0; j < col; j++)
    {
        cin >> map[i][j];
    }

    priority_queue<node, vector<node>, cmp> q;
    cost[0][0] = 1;
    q.push({0, 0, map[0][0]});

    while (!q.empty())
    {
        node current = q.top();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            node next = {current.x + dx[i], current.y + dy[i], map[next.x][next.y]};
            
            if(next.x < 0 || next.y < 0 || next.x >= row || next.y >= col || map[next.x][next.y] >= map[current.x][current.y]) continue;
            cost[next.x][next.y] += cost[current.x][current.y];
            
            if(visit[next.x][next.y]) continue;
            visit[next.x][next.y] = true;

            q.push(next); 
        }
    }
    cout << cost[row-1][col-1];
}