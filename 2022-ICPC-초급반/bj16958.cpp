#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
typedef long long ll;

const int MAX_NUM = 987654321;
int N, T, M, s, x, y, a, b;
int dp[1001][1001];
pair<int, pair<int, int>> dot[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> T;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = MAX_NUM;
		}
	}

	for (int i = 1; i <= N; i++) {
		cin >> s >> x >> y;

		dot[i] = { s, {x, y} };

		for (int j = 1; j < i; j++) {
			if (dot[i].first == 1 && dot[j].first == 1) {
				dp[i][j] = min(dp[i][j], min(T, abs(dot[i].second.first - dot[j].second.first) + abs(dot[i].second.second - dot[j].second.second)));
				dp[j][i] = min(dp[j][i], min(T, abs(dot[i].second.first - dot[j].second.first) + abs(dot[i].second.second - dot[j].second.second)));
			}
			else {
				dp[i][j] = min(dp[i][j], abs(dot[i].second.first - dot[j].second.first) + abs(dot[i].second.second - dot[j].second.second));
				dp[j][i] = min(dp[j][i], abs(dot[i].second.first - dot[j].second.first) + abs(dot[i].second.second - dot[j].second.second));
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (i == j || i == k || j == k) continue;
				
				if (dp[j][k] > dp[j][i] + dp[i][k])
					dp[j][k] = dp[j][i] + dp[i][k];
			}
		}
	}

	cin >> M;

	while (M--) {
		cin >> a >> b;

		cout << dp[a][b] << "\n";
	}
}