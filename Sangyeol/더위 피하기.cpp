//BOJ 15938 더위 피하기
#include <iostream>
#include <queue>
#include <memory.h>
#define DIV_NUM 1000000007
using namespace std;

struct Point
{
	int x, y;
};

Point home;
int dX[4] = { 0, 1, 0, -1 };
int dY[4] = { 1, 0, -1 ,0 };
int diffX, diffY, currentTime;
long long int ans = 0;
int dp[2][401][401] = { 0 }; // time, y, x
bool block[401][401] = { false };

void turnQueue(queue<Point>& srcQueue, queue<Point>& targetQueue) {
		while (!srcQueue.empty()) {
			Point current = srcQueue.front();
			srcQueue.pop();

			for (int i = 0; i < 4; i++) {
				int nX = current.x + dX[i];
				int nY = current.y + dY[i];
				if (nX >= 0 && nX <= 400 && nY >= 0 && nY <= 400 && !block[nY][nX]) {
					if (nX == home.x && nY == home.y) {
						ans += dp[currentTime][current.y][current.x];
						ans %= DIV_NUM;
					}
					else {
						if (dp[(currentTime + 1) % 2][nY][nX] == 0) {
							targetQueue.push({ nX,nY });
						}
						dp[(currentTime + 1) % 2][nY][nX] += dp[currentTime][current.y][current.x];
						dp[(currentTime + 1) % 2][nY][nX] %= DIV_NUM;
					}
				}
			}
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N;
	queue<Point> q1, q2;

	cin >> diffX >> diffY;
	cin >> T;
	cin >> home.x >> home.y;
	home.x -= diffX - 200;
	home.y -= diffY - 200;
	cin >> N;

	for (int i = 0; i < N; i++) {
		Point temp;
		cin >> temp.x >> temp.y;
		temp.x -= diffX - 200;
		temp.y -= diffY - 200;
		if (temp.x >= 0 && temp.x <= 400 && temp.y >= 0 && temp.y <= 400)
			block[temp.y][temp.x] = true;
	}
	currentTime = 0;
	dp[currentTime][200][200] = 1;
	q1.push({ 200,200 });
	while (T--) {
		if (currentTime) {
			turnQueue(q2, q1);
		}
		else {
			turnQueue(q1, q2);
		}
		memset(dp[currentTime], 0, sizeof(int) * 401 * 401);
		currentTime = (currentTime + 1) % 2;
	}
	
	cout << ans;
}