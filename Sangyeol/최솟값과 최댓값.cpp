// BOJ 2357 ÃÖ¼Ú°ª°ú ÃÖ´ñ°ª
#include <iostream>
#include <vector>
#define MAX_VALUE 1234567890
#define MIN_VALUE 0
using namespace std;

int insert(int index, vector<int>& seg, bool isMin) {
	if (isMin) {
		if (index >= seg.size()) {
			return MAX_VALUE;
		}
		if (seg[index] != MAX_VALUE)
			return seg[index];
		return seg[index] = min(insert(index * 2, seg, isMin), insert(index * 2 + 1, seg, isMin));
	}
	else {
		if (index >= seg.size()) {
			return MIN_VALUE;
		}
		if (seg[index] != MIN_VALUE)
			return seg[index];
		return seg[index] = max(insert(index * 2, seg, isMin), insert(index * 2 + 1, seg, isMin));
	}
}

int find(int start, int end, int left, int right, int current, vector<int>& seg, bool isMin) {
	if (start > right || end < left) {
		if (isMin) {
			return MAX_VALUE;
		}
		else {
			return MIN_VALUE;
		}
	}
	if (start >= left && end <= right) {
		return seg[current];
	}
	int mid = (start + end) >> 1;
	if (isMin) {
		return min(find(start, mid, left, right, current << 1, seg, isMin), find(mid + 1, end, left, right, (current << 1) + 1, seg, isMin));
	}
	else {
		return max(find(start, mid, left, right, current << 1, seg, isMin), find(mid + 1, end, left, right, (current << 1) + 1, seg, isMin));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, a, b;
	cin >> N >> M;
	int size = 1;
	while (size < N) {
		size <<= 1;
	}

	vector<int> maxSeg(size << 1, MIN_VALUE);
	vector<int> minSeg(size << 1, MAX_VALUE);

	for (int i = 0; i < N; i++) {
		cin >> maxSeg[size + i];
		minSeg[size + i] = maxSeg[size + i];
	}
	insert(1, minSeg, true);
	insert(1, maxSeg, false);
	
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		cout << find(1, size, a, b, 1, minSeg, true) << ' ' << find(1, size, a, b, 1, maxSeg, false) << '\n';
	}
}