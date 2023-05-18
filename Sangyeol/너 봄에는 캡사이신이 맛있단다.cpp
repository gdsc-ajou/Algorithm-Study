// BOJ 15824 너 봄에는 캡사이신이 맛있단다
#include <iostream>
#include <vector>
#include <algorithm>
#define DIV_NUM 1000000007
using namespace std;

long long int pow2(int n) {
	if (n == 1)
		return 2;
	long long int temp = pow2(n >> 1);
	temp %= DIV_NUM;
	if (n & 1) {
		return temp * temp * 2 % DIV_NUM;
	}
	else {
		return temp * temp % DIV_NUM;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	long long int ans = 0;

	cin >> N;
	vector<int> vec(N);
	vector<int> dp(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	for (int i = 1; i < N; i++) {
		long long int temp = dp[i - 1] * 2 % DIV_NUM;
		temp += (pow2(i) - 1) * ((long long int)vec[i] - vec[i - 1]);
		ans += dp[i] = temp % DIV_NUM;
		ans %= DIV_NUM;
	}
	cout << ans;
}