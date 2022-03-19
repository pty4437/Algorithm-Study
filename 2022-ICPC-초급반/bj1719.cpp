#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

const int MAX_NUM = 98765432;

int n, m, a, b, c;
int dp[201][201], res[201][201];
vector<pair<int, int>> adj[201];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dp[i][j] = 0;
			else dp[i][j] = MAX_NUM;
		}
	}

	while (m--) {
		cin >> a >> b >> c;
		if (dp[a][b] > c) {
			dp[a][b] = c;
			dp[b][a] = c;
			res[a][b] = b;
			res[b][a] = a;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (dp[j][k] > dp[j][i] + dp[i][k]){
					dp[j][k] = dp[j][i] + dp[i][k];

					res[j][k] = res[j][i];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || dp[i][j] == MAX_NUM)
				cout << "-" << " ";
			else
				cout << res[i][j] << " ";
		}
		cout << endl;
	}
}