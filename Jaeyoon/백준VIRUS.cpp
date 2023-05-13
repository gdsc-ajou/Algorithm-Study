#include <stdio.h>

int graph[101][101] = {};
int visited[101] = {};

int dfs(int v, int num) {
    visited[v] = 1;
    int count = 1;
    for(int i = 1; i <= num; i++) { 
        if(graph[v][i] && !visited[i]) { 
            count += dfs(i, num);
        }
    }
    return count;
}

int main() {
    int num, link;
    scanf("%d", &num);
    scanf("%d", &link);
    for(int i = 0; i < link; i++) {
        int a , b;
        scanf("%d %d", &a, &b);
        
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    printf("%d\n", dfs(1, num) - 1);
    return 0;
}