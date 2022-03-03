#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, K;
ll dp[1001][1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			if (i == j || j == 0) {
				dp[i][j] = 1; continue;
			}
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
		}
	}

	cout << dp[N][K];

	return 0;
}