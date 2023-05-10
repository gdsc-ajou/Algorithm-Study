//BOJ 2042 구간 합 구하기
#include <iostream>
#include <vector>
using namespace std;

long long int sum(int start, int end, int current, int left, int right, vector<long long int>& vec) {
	if (left > end || right < start) 
		return 0;
	if (left <= start && right >= end) 
		return vec[current];
	int mid = (start + end) >> 1;
	return sum(start, mid, current * 2, left, right, vec) + sum(mid + 1, end, current * 2 + 1, left, right, vec);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;

	int size = 1;
	while (size < N) {
		size <<= 1;
	}
	vector<long long int> vec((size << 1) + 1);

	for (int i = 0; i < N; i++) {
		int index = i + size;
		long long int value;
		cin >> value;
		while (index != 0) {
			vec[index] += value;
			index >>= 1;
		}
	}

	for (int i = 0; i < M + K; i++) {
		long long int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			// 변경
			int index = size + b - 1;
			long long int value = c - vec[index];
			while(index != 0) {
				vec[index] += value;
				index >>= 1;
			}
		}
		else {
			// 구간합
			if (b > c)
				swap(b, c);
			cout << sum(0, size - 1, 1, b - 1, c - 1, vec) << '\n';
		}
	}
}