#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll n,tmp, ans;
vector <pair<ll, ll>> v;

const ll n_ = 3e6 + 100;
ll tree[n_], arr[n_];

ll init(ll N, ll s, ll e) {
	if (s == e) return tree[N] = arr[s];
	ll mid = (s + e) / 2;
	return tree[N] = init(N * 2, s, mid) + init(N * 2 + 1, mid + 1, e);
}

void update(ll N, ll s, ll e, ll idx, ll val) {
	if (idx > e || idx < s) return;
	if (s == e) {
		if (idx == s) tree[N] = val;
		return;
	}
	ll mid = (s + e) / 2;
	update(N * 2, s, mid, idx, val);
	update(N * 2 + 1, mid + 1, e, idx, val);
	tree[N] = tree[N * 2] + tree[N * 2 + 1];
}

ll query(ll N, ll s, ll e, ll l, ll r) {
	if (l > e || r < s) return 0;
	if (l <= s && e <= r) return tree[N];
	ll mid = (s + e) / 2;

	return query(N * 2, s, mid, l, r) + query(N * 2 + 1, mid + 1, e, l, r);
}

bool compare(pair<ll, ll> A, pair<ll, ll> B) {
	if (A.first == B.first)
		return A.second < B.second;

	return A.first > B.first;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	ans = 0;

	for (ll i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(pair<ll, ll>(tmp, i));
	}

	sort(v.begin(), v.end(), compare);

	for (ll i = 0; i < n; i++) {
		ans += query(1, 0, n - 1, 0, v[i].second);
		update(1, 0, n - 1, v[i].second, 1);
	}

	cout << ans;
	

}
