#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[50002][2];
vector<int> v[50002];

void dfs(int chi, int par) {
	dp[chi][1] = 1;
	for (auto next : v[chi]) {
		if (next == par) continue;
		dfs(next, chi);
		dp[chi][0] += max(dp[next][0], dp[next][1]);
		dp[chi][1] += dp[next][0];
	}
}

int main(void) {
	int N, A, B;
	scanf("%d", &N);

	for(int i = 1; i < N; i++){
		scanf("%d %d", &A, &B);

		v[A].push_back(B);
		v[B].push_back(A);
	}

	dfs(1, 0);
	printf("%d\n", max(dp[1][0], dp[1][1]));

	return 0;
}