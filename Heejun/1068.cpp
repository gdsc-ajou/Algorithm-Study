// 1068 Æ®¸®

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adjList;
int root_num = 0, node_num = 0, deleted_node = 0; 

void create_tree();
void count_leaf(int deleted_node);

int main()
{
    create_tree();
    count_leaf(deleted_node);
}

void create_tree()
{
    cin >> node_num;
    adjList.resize(node_num);
    for(int i = 0; i < node_num; i++) 
    {
        int parent; cin >> parent;
        if(parent == -1) root_num = i;
        else adjList[parent].push_back(i);
    }
    cin >> deleted_node;
}

void count_leaf(int deleted_node)
{
    if(deleted_node == root_num) {cout << 0; return;}
    queue<int> q;
    int leaf_count = 0;
    q.push(root_num);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        if(adjList[current].empty()) leaf_count++;
        for(int i = 0; i < adjList[current].size(); i++)
        {
            int next = adjList[current][i];
            if(next == deleted_node)
            { 
                if(adjList[current].size() == 1) leaf_count++;
                continue;
            }
            q.push(next);
        }
    }

    cout << leaf_count;
}
