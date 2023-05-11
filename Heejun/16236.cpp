#include <iostream>
#include <queue>

using namespace std;

int map[20][20] = {0};
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int map_size = 0;

struct fish
{
    int x, y, size;
};

struct cmp
{
    bool operator()(fish& a, fish& b)
    {
        if(a.size == b.size)
        {
            if(a.x == b.x)
            {
                return a.y > b.y;
            } 
            return a.x > b.x;
        }
        return a.size > b.size;
    }
};

int findFood(fish& babeShark);

int main()
{
    int count = 0; 
    fish babeShark;

    cin >> map_size;
    for(int i = 0; i < map_size; i++) for(int j = 0; j < map_size; j++)
    {
        cin >> map[i][j];
        if(map[i][j] == 9) {babeShark = {i, j, 2}; map[i][j] = 0;}
    }
    
    int size_up_count = babeShark.size;
    for(int result = findFood(babeShark); result != 0; result = findFood(babeShark)) 
    {
        count += result;
        if(0 == --size_up_count) size_up_count = ++babeShark.size;  
    }

    cout << count;
}

int findFood(fish& babeShark)
{
    priority_queue<fish, vector<fish>, cmp> q;
    bool visit[20][20] = {false};
    q.push({babeShark.x, babeShark.y , 0});
    visit[babeShark.x][babeShark.y] = true;

    while(!q.empty())
    {
        fish current = q.top();
        q.pop();

        if(map[current.x][current.y] != 0 && map[current.x][current.y] < babeShark.size) 
        {
            babeShark.x = current.x; babeShark.y = current.y;
            map[current.x][current.y] = 0; 
            return current.size;
        }


        for(int i = 0; i < 4; i++)
        {
            fish next = {current.x + dx[i], current.y + dy[i], current.size + 1};
            if(next.x < 0 || next.y < 0 || next.x >= map_size || next.y >= map_size) continue;

            if(visit[next.x][next.y] || map[next.x][next.y] > babeShark.size) continue;
            visit[next.x][next.y] = true;
            q.push(next);
        }
    }

    return 0;
}