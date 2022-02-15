#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n, m, a, b, c, d, x, y, t;
const ll p = 26, mod = 200003;
string s;

bool f(int m) {
	ll hash = 0, pw = 1;

	for (int i = 0; i < m; i++)hash = (hash * p + s[i]) % mod, pw = (pw * p) % mod;

	vector<ll> v[mod]; v[hash].push_back(0);

	for (int i = 1; i + m - 1 < n; i++) {
		hash = (hash * p % mod - pw * s[i - 1] % mod + s[i - 1 + n] + mod) % mod;
		for (ll nxt : v[hash])
			if (!strncmp(&s[nxt], &s[i], m)) return true;
		v[hash].push_back(i);
	}

	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> s;


	n = s.size();

	ll l = 0, r = n, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (f(mid)) {
			ans = max(ans, mid);
			l = mid + 1;
		}
		else r = mid - 1;
	}

	cout << ans;
}