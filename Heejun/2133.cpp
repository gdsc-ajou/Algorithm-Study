//2133 타일 채우기

#include <iostream>

using namespace std;

void input();
void print_case();

int n;
int tileCase[16];

int main()
{
    input();
    print_case();
}

void input()
{
    cin >> n;
}

void print_case()
{
    if(n % 2 != 0) {cout << 0; return;}

    n /= 2;
    tileCase[0] = 1;
    tileCase[1] = 3;
    for(int i = 2; i <= n; i++)
    {
        tileCase[i] += tileCase[i-1]*3;
        for(int j = i - 2; j >= 0; j--)
        {
            tileCase[i] += tileCase[j]*2;
        }
    }

    cout << tileCase[n];
}