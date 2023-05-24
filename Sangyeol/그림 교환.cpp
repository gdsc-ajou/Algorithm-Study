//BOJ 1029 그림 교환
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<short>> map;
vector<vector<vector<short>>> dp;

int getAns(int index, int current, int cost) {
	if (dp[current][index][cost] != -1)
		return dp[current][index][cost];
	int ret = 1;
	for (int i = 0; i < N; i++) {
		if (!(index & 1 << i) && cost <= map[current][i]) {
			ret = max(ret, 1 + getAns(index | 1 << i, i, map[current][i]));
		}
	}
	return dp[current][index][cost] = ret;
}

int main() {
	cin >> N;
	map = vector<vector<short>>(N, vector<short>(N));
	dp = vector<vector<vector<short>>>(N, vector<vector<short>>(2 << (N + 1), vector<short>(10, -1)));

	getchar();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char temp = getchar();
			map[i][j] = temp - '0';
		}
		getchar();
	}

	cout << getAns(1, 0, 0);
}