// 12865 Æò¹üÇÑ ¹è³¶

#include <iostream>
#include <vector>

using namespace std;

void input();
void print_maxValue();

int thing_num, maxWeight;
vector<pair<int, int>> list;

int maxValue_per_weight[100001] = {0};

int main()
{
    input();
    print_maxValue();
}

void input()
{
    cin >> thing_num >> maxWeight;
    for(int i = 0; i < thing_num; i++)
    {
        pair<int, int> tmp;
        cin >> tmp.first >> tmp.second;
        list.push_back(tmp);
    }
}

void print_maxValue()
{
    for(int i = 0; i < thing_num; i++)
    {
        for(int j = maxWeight; j > 0; j--)
        {
            if(j < list[i].first) continue;
            maxValue_per_weight[j] = max(maxValue_per_weight[j], maxValue_per_weight[j - list[i].first] + + list[i].second) ;
        }
    }

    cout << maxValue_per_weight[maxWeight];
}