#include <iostream>

using namespace std;

int q_num = 0;
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
    
    cin >> q_num;
    for(int i = 0; i < q_num; i++)
    {
        int init, add_block, coord;
        cin >> init >> add_block >> coord;

        int current_floor = 1, total_block;
        int current_block = total_block = init;

        while (total_block < coord)
        {
            current_floor++;
            current_block += add_block;
            total_block += current_block; 
        }
        cout << current_floor << " " << current_block - (total_block - coord) << "\n";    
    }
}