#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

const int MAX_NUM = (100000*100) + 1;
int n, m, a, b, c;
int dp[101][101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = MAX_NUM;
		}
	}

	while (m--) {
		cin >> a >> b >> c;

		if(dp[a][b] > c)
			dp[a][b] = c;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (j == k || j == i || i == k) continue;

				if (dp[j][k] > dp[j][i] + dp[i][k])
					dp[j][k] = dp[j][i] + dp[i][k];
			}
		}
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] == MAX_NUM || i == j)
				cout << 0 << " ";
			else
				cout << dp[i][j] << " ";
		}

		cout << "\n";
	}

	return 0;
}