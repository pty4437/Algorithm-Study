#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

const ll n_ = 3e6 + 10;
const ll inf = 99999999999999;

ll dp[n_];
ll n, m, res, a, b, c;

bool compare(pair<ll, pair<ll, ll>> A, pair<ll, pair<ll, ll>> B) {
	if (A.first == B.first) {
		if (A.second.second == B.second.second)
			return A.second.first > B.second.first;
		return A.second.second < B.second.second;
	}

	return A.first < B.first;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;

	cin >> T;

	while (T--) {

		cin >> n >> m;

		for (int i = 1; i <= n; i++)dp[i] = inf;

		dp[0] = 0;
		res = inf;

		vector<pair<ll, pair<ll, ll>>>v(m);

		for (int i = 0; i < m; i++)cin >> v[i].second.first >> v[i].first >> v[i].second.second;

		sort(v.begin(), v.end(), compare);


		for (int ii = 0; ii < m; ii++) {
			a = v[ii].second.first, b = v[ii].first, c = v[ii].second.second;
			for (int i = n; i >= 0; i--) {
				if (i + a >= n) res = min(res, dp[i] + (n - i) * b + c);
				if (i >= a) dp[i] = min(dp[i], dp[i - a] + a * b + c);
			}
		}

		cout << res << "\n";
	}
}