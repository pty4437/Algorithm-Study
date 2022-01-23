#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll N, M;
const ll _n = 3e6 + 100;
ll tree[_n], arr[_n], lazy[_n];

ll init(ll N, ll s, ll e) {
	if (s == e) return tree[N] = arr[s];
	ll mid = (s + e) / 2;
	return tree[N] = init(N * 2, s, mid) + init(N * 2 + 1, mid + 1, e);
}

ll update_lazy(ll N, ll s, ll e) {
	if (lazy[N] != 0) {
		tree[N] += (e - s + 1) * lazy[N];
		if (s != e) {
			lazy[N * 2] += lazy[N];
			lazy[N * 2 + 1] += lazy[N];
		}
		lazy[N] = 0;
	}
}

ll query(ll N, ll s, ll e, ll l, ll r) {
	update_lazy(N, s, e);

	if (l > e || r < s) return 0;
	if (l <= s && e <= r) return tree[N];
	ll mid = (s + e) / 2;
	return query(N * 2, s, mid, l, r) + query(N * 2 + 1, mid + 1, e, l, r);
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

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	

	for (ll i = 0; i < N; i++) cin >> arr[i];

	init(1, 0, N - 1);

	cin >> M;

	for (ll i = 0; i < M; i++) {
		ll a, b, c, d;
		cin >> a;

		if (a == 1) {
			cin >> b >> c >> d;
			for (ll j = b - 1; j <= c - 1; j++)
				update(1, 0, N - 1, j, d);
		}
		else {
			cin >> b;
			cout << tree[1] - query(1, 0, N - 1, b - 1) << "\n";
		}
	}

}