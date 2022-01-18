#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cost[17][17];
int dp[(1 << 17)][17];

int main(void) {
	int N, ans;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &cost[i][j]);

	ans = 999999999;

	for (int x = 0; x < N; x++) {
		for (int i = 1; i < (1 << N); i++)
			for (int j = 0; j < N; j++) dp[i][j] = 999999999;
		dp[(1 << x)][x] = 0;

		for (int i = 0; i < (1 << N); i++) {
			for (int j = 0; j < N; j++) {
				if (!(i & (1 << j))) continue;
				for (int k = 0; k < N; k++) {
					if (!cost[j][k] || (i & (1 << k)))continue;
					int tmp = i | (1 << k);
					dp[tmp][k] = min(dp[tmp][k], dp[i][j] + cost[j][k]);
				}
			}
		}

		for (int i = 0; i < N; i++) if (cost[i][x]) ans = min(ans, dp[(1 << N) - 1][i] + cost[i][x]);
	}

	printf("%d\n", ans);


	return 0;
}