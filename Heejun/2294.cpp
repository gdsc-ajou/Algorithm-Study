// 2294 µ¿Àü2

#include <iostream>
#define INF 10000000

using namespace std;

int coin_num = 0, maxValue = 0;
int count_per_value[10001] = {0};
int coin[100] = {0};


void input();
void lestCount();

int main()
{
    input();
    lestCount();
}

void input()
{
    cin >> coin_num >> maxValue;
    for(int i = 0; i < coin_num; i++) cin >> coin[i];
    for(int i = 1; i <= maxValue; i++) count_per_value[i] = INF;
}

void lestCount()
{
    for(int i = 0; i < coin_num; i++)
    {
        for(int j = coin[i]; j <= maxValue; j++)
        {
            count_per_value[j] = min(count_per_value[j], count_per_value[j-coin[i]] + 1);
        }
    }

    if(count_per_value[maxValue] == INF) cout << -1;
    else cout << count_per_value[maxValue];
}