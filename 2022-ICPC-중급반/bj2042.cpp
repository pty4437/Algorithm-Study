#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll n = 3e6 + 100;

ll tree[n], arr[n];

ll init(ll N, ll s, ll e) {
	if (s == e) return tree[N] = arr[s];
	ll mid = (s + e) / 2;
	return tree[N] = init(N * 2, s, mid) + init(N * 2 + 1, mid + 1, e);
}

ll query(ll N, ll s, ll e, ll l, ll r) {
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

	ll N, M, K;

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) cin >> arr[i];

	init(1, 0, N - 1);

	ll a, b, c;

	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) update(1, 0, N - 1, b - 1, c);
		else cout << query(1, 0, N - 1, b - 1, c - 1) << "\n";
	}

	return 0;
}