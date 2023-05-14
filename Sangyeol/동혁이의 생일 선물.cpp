//BOJ 15319 동혁이의 생일선물
#include<iostream>
#define DIV_NUM 1000000007
using namespace std;

int main() {
	long long int ans = 0;
	int N, x, k;
	cin >> N;
	while (N--) {
		cin >> x >> k;
		long long int temp = 1;
		while(k) {
			if (k & 1) {
				ans += temp;
				ans %= DIV_NUM;
			}
			temp *= x;
			temp %= DIV_NUM;
			k >>= 1;
		}
	}
	cout << ans % DIV_NUM;
}