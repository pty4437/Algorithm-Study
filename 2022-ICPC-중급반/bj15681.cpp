#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dp[100002];
vector<int> v[100002];

void dfs(int chi, int par) {
	dp[chi] = 1;

	for (auto next : v[chi]) {
		if (next == par) continue;
		dfs(next, chi);
		dp[chi] += dp[next];
	}
}

int main(void) {
	int N, R, Q;
	int A, B;

	scanf("%d %d %d", &N, &R, &Q);

	for (int i = 1; i < N; i++) {
		scanf("%d %d", &A, &B);

		v[A].push_back(B);
		v[B].push_back(A);
	}

	dfs(R, 0);

	for (int i = 0; i < Q; i++) {
		scanf("%d", &A);
		printf("%d\n", dp[A]);
	}

	return 0;
}