#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;
using namespace std;

ll a, b, c, n, m, k;
ll dp[3001][10010];
vector<pair<ll, ll>> v;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	v.push_back({ 0,0 });

	while (n--) {
		cin >> a >> b >> c;
		ll temp = 1, sum = 0;
		while (sum + temp <= c) {
			v.push_back({ a * temp, b * temp });
			sum += temp;
			temp *= 2;
		}

		if (c - sum) {
			v.push_back({ a * (c - sum), b * (c - sum) });
		}
	}

	int h = v.size();
	for (int i = 1; i < h; i++) {
		for (int j = 0; j <= m; j++) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (j >= v[i].first)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i].first] + v[i].second);
		}
	}

	ll res = 0;

	for (int i = 0; i <= m; i++)
		res = max(res, dp[h - 1][i]);

	cout << res;
}