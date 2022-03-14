#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;
typedef long long ll;

#define INF (400 * 10000 + 1)

int V, E, a, b, c;
int dp[401][401];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E;
	fill(&dp[1][1], &dp[V][V + 1], INF);
	
	while (E--) {
		cin >> a >> b >> c;
		dp[a][b] = c;
	}

	for (int m = 1; m <= V; m++) {
		for (int f = 1; f <= V; f++) {
			for (int t = 1; t <= V; t++) {
				if (dp[f][t] > dp[f][m] + dp[m][t]) {
					dp[f][t] = dp[f][m] + dp[m][t];
				}
			}
		}
	}

	int res = INF;

	for (int i = 1; i <= V; i++)
		res = min(res, dp[i][i]);

	cout << ((res == INF) ? -1 : res);
}