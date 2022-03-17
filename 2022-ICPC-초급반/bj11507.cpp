#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, res = 0;
ll dp[1001][10];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] = dp[i][j] + dp[i - 1][k];
				dp[i][j] %= 10007;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		res += dp[N][i];
	}
	res %= 10007;

	cout << res;
}