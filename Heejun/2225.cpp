//2225 ÇÕºÐÇØ

#include <iostream>

using namespace std;

void input();
void print_sum_case();

int n, k;
long long num_case[201] = {0};

int main()
{
    input();
    print_sum_case();
}

void input()
{
    cin >> n >> k;
    for(int i = 0; i <= n; i++) num_case[i] = 1;
}

void print_sum_case()
{
    for(int i = 2; i <= k; i++) for(int j = 1; j <= n; j++)
    {
        num_case[j] += num_case[j-1];
        num_case[j] %= 1000000000;
    }

    cout << num_case[n];
}