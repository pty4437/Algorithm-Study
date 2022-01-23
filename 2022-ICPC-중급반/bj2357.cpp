#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
ll N, M, a, b;

const ll n_ = 1000002;
ll minTree[n_], maxTree[n_], arr[n_], tmp;


void init(ll N, ll s, ll e) {
	if (s == e) {
		minTree[N] = maxTree[N] = arr[s];
		return;
	}
	ll mid = (s + e) / 2;

	init(N * 2, s, mid);
	init(N * 2 + 1, mid + 1, e);

	minTree[N] = min(minTree[N * 2], minTree[N * 2 + 1]);
	maxTree[N] = max(maxTree[N * 2], maxTree[N * 2 + 1]);

	return;
}

pair<ll, ll> query(ll N, ll s, ll e, ll l, ll r) {
	if (l > e || r < s) return make_pair(INT32_MAX, 0);
	if (l <= s && e <= r) return make_pair(minTree[N], maxTree[N]);
	ll mid = (s + e) / 2;
	
	pair<ll, ll> left, right;
	left = query(N * 2, s, mid, l, r);
	right = query(N * 2 + 1, mid + 1, e, l, r);

	return make_pair(min(left.first, right.first), max(left.second, right.second));
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll num;
	pair<ll, ll> result;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	init(1, 1, N);

	for (int i = 0; i < M; i++) {
		cin >> a >> b;

		result = query(1, 1, N, a, b);

		cout << result.first << " " << result.second << "\n";
	}
}