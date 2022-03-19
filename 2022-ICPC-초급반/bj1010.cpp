#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int T, N, M;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	while (T--) {
		ll dp[31][31];

		cin >> N >> M;

		dp[0][0] = 1;

		for (int i = 1; i <= N; i++) {
			dp[0][i] = 0;
		}

		for (int i = 1; i <= M; i++) {
			for (int j = 0; j <= N; j++) {
				if (i == j) dp[i][j] = 1;
				else if (j == 0) dp[i][j] = 1;
				else
					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
		}

		cout << dp[M][N] << endl;
	
	}
}