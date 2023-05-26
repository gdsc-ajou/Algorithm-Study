//BOJ 2213 트리의 독립집합
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> weight;
vector<vector<int>> dp; // 0은 해당 노드 선택 X, 1은 선택 
vector<vector<int>> adjVec;
vector<int> ansVec;

void find(int current, int parent) {
	dp[current][1] += weight[current];
	for (int next : adjVec[current]) {
		if (next == parent)
			continue;
		find(next, current);
		dp[current][0] += max(dp[next][0], dp[next][1]);
		dp[current][1] += dp[next][0];
	}
}
void makeAns(int current, int parent, bool isParentCheck) {
	bool isCheck = false;
	if (!isParentCheck && dp[current][0] < dp[current][1]) {
		ansVec.push_back(current);
		isCheck = true;
	}
	for (int next : adjVec[current]) {
		if (next == parent)
			continue;
		makeAns(next, current, isCheck);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	weight = vector<int>(N + 1);
	dp = vector<vector<int>>(N + 1, vector<int>(2, 0));
	adjVec = vector<vector<int>>(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> weight[i];
	}
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		adjVec[a].push_back(b);
		adjVec[b].push_back(a);
	}
	find(1, 0);
	makeAns(1, 0, false);
	sort(ansVec.begin(), ansVec.end());
	cout << max(dp[1][0], dp[1][1]) << '\n';
	for (int i : ansVec) {
		cout << i << ' ';
	}
}