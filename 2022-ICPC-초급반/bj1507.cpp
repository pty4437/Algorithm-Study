#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, val = 0;
int dp[21][21], tmp[21][21];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			cin >> dp[i][j];
			val += dp[i][j];
		}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if ((i != j && j != k && i != k) && (dp[j][k] > dp[j][i] + dp[i][k])) {
					cout << -1;
					return 0;
				}
				else if ((i != j && j != k && i != k) && (dp[j][k] == dp[j][i] + dp[i][k])) {
					tmp[j][k] = -1;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (tmp[i][j] == -1) {
				val -= dp[i][j];
			}
		}
	}

	cout << val / 2;
}