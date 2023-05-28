// 11403 경로찾기

#include <iostream>

using namespace std;

void input();
void findRoute();

int side_length = 0;
bool route[100][100] = {false};

int main()
{
    input();
    findRoute();
}

void input()
{
    cin >> side_length;
    for(int i = 0; i < side_length; i++) for(int j = 0; j < side_length; j++)
    {
        int tmp; cin >> tmp;
        route[i][j] = tmp;
    }
}

void findRoute()
{
    for(int k = 0; k < side_length; k++) for(int i = 0; i < side_length; i++) for(int j = 0; j < side_length; j++) 
        if(route[i][k] && route[k][j]) route[i][j] = true;

    for(int i = 0; i < side_length; i++)
    {
        for(int j = 0; j < side_length; j++)
            cout << route[i][j] << " ";
        cout << "\n";
    }
}
