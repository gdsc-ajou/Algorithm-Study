//BOJ 11086 ³ªÀÌÆ®ÀÇ ¿°Å½
#include<iostream>
#include<vector>
#include<queue>
#define DIV_NUM 1000000009
using namespace std;

struct Point {
	int r, c, distance;
};

struct DP {
	long long int numOfPossible = 0;
	int distance = -1;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int r, c;
	int dR[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int dC[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	cin >> r >> c;
	vector<vector<DP>> dp(r + 1, vector<DP>(c + 1));

	queue<Point> q;
	dp[1][1].numOfPossible = 1;
	dp[1][1].distance = 0;
	q.push({1, 1, 0});
	while (!q.empty()) {
		Point current = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nR = current.r + dR[i];
			int nC = current.c + dC[i];
			if (nR >= 1 && nR <= r && nC >= 1 && nC <= c) {
				if (dp[nR][nC].distance == -1) {
					dp[nR][nC].distance = current.distance + 1;
					q.push({ nR,nC, current.distance + 1 });
				}
				if (dp[nR][nC].distance == current.distance + 1){
					dp[nR][nC].numOfPossible += dp[current.r][current.c].numOfPossible;
					dp[nR][nC].numOfPossible %= DIV_NUM;
				}
			}
		}
	}
	if (dp[r][c].distance == -1) {
		cout << "None";
	}
	else {
		cout << dp[r][c].distance << ' ' << dp[r][c].numOfPossible % DIV_NUM;
	}
}