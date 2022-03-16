#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

const int MAX_NUM = 987654321;
int N, M, a, b, res = 0;
int dp[501][501], cnt[501];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			dp[i][j] = MAX_NUM;

	while (M--) {
		cin >> a >> b;

		dp[a][b] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (dp[j][k] > dp[j][i] + dp[i][k])
					dp[j][k] = dp[j][i] + dp[i][k];
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {		
			if (i == j) {
				cnt[i]++;
			}
			else if (dp[i][j] != MAX_NUM) {
				cnt[i]++; cnt[j]++;
			}
		}

	}

	for (int i = 1; i <= N; i++) {
		if (cnt[i] == N) res++;
	}

	cout << res << endl;
}