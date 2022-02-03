#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll N, K;

	cin >> N >> K;
	vector<ll> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	ll s = 0, e = 2000000000, ans;

	while (s <= e) {
		ll mid = (s + e) / 2, sum = 0;
		for (int i = 0; i < N; i++)
			sum += max(mid - v[i], (ll)0);

		if (sum > K)
			e = mid - 1;
		else {
			ans = mid;
			s = mid + 1;
		}
	}

	cout << ans;
}
