// 11725 트리의 부모 찾기
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adjList;
int parent[100001] = {0};
int main()
{
    int n; cin >> n;
    adjList.resize(n + 1);
    for(int i = 0; i < n - 1; i++)
    {
        int start, end; cin >> start >> end;
        adjList[start].push_back(end);
        adjList[end].push_back(start);
    }

    queue<pair<int, int>> q;
    q.push({1, 1});

    while (!q.empty())
    {
        int previous = q.front().first;
        int current = q.front().second;
        q.pop();

        if(previous == 0) continue;

        for(auto it = adjList[current].begin(); it != adjList[current].end(); it++)
        {
            int next = *it;

            if(next == previous) continue;            
            q.push({current, next});
            parent[next] = current;
        }
    }
    
    for(int i = 2; i <= n; i++)
    {
        cout << parent[i] << "\n";
    }
}