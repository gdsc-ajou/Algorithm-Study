//BOJ 16565 N포커
#include<iostream>
#define DIV_NUM 10007
using namespace std;

int dp[53][53] = { 0 }; // n개의 카드중 m개를 뽑아 포카드가 되지않게 만드는 경우의 수
int combi[53][53] = { 0 };

int combination(int n, int r) {
	if (combi[n][r] != 0)
		return combi[n][r];
	long long int ret = 1;

	for (int i = 0; i < r; i++) {
		ret *= ((long long int)n - i);
		ret /= i + 1;
	}
	ret %= DIV_NUM;
	return combi[n][r] = ret;
}

int find(int n, int m) {
	if (dp[n][m] != 0) {
		return dp[n][m];
	}
	if (m == 0) {
		return dp[n][m] = 1;
	}
	if (n == m)
		return dp[n][m] = 0;
	long long int ret;
	if (m <= 3) {
		ret = combination(n, m);
	}
	else {
		ret = combination(n, m);
		int numOfFour = 1;
		while (m - (numOfFour - 1) * 4 > 3) {
			ret -= combination(n / 4, numOfFour) * find(n - 4 * numOfFour, m - 4 * numOfFour);
			numOfFour++;
		}
	}
	return dp[n][m] = ret;
}

int main() {
	int N;
	long long int ans = 0;
	
	cin >> N;
	if (N > 3) {
		int numOfFour = 1;
		while (N - (numOfFour - 1) * 4 > 3) {
			ans += combination(13, numOfFour) * find(52 - numOfFour * 4, N - numOfFour * 4);
			ans %= DIV_NUM;
			numOfFour++;
		}
	}
	cout << ans;
}