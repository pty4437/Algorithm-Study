#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N;
int game[101][101];
int dp[101][101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> game[i][j];
		}
	}

	dp[1][1] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!dp[i][j] || (i == N && j == N)) continue;

			int val = game[i][j];
			int down = val + i;
			int right = val + j;

			if (down <= N) dp[down][j] += dp[i][j];
			if (right <= N) dp[i][right] += dp[i][j];
		}

	}

	cout << dp[N][N];

}