// 2293 µ¿Àü1

#include <iostream>

using namespace std;

int coin_num, sum;
int value[100] = {0};
int num_per_value[10001] = {1, };

void input();
void print_num();

int main()
{
    input();
    print_num();
}

void input()
{
    cin >> coin_num >> sum;
    for(int i = 0; i < coin_num; i++) cin >> value[i];
}

void print_num()
{
    for(int i = 0; i < coin_num; i++)
    {
        for(int j = value[i]; j <= sum; j++)
        {
            if(j < value[i]) continue;
            num_per_value[j] += num_per_value[j - value[i]];
        }
    }
    cout << num_per_value[sum];
}
