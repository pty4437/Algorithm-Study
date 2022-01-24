#define _CRT_SECURE_NO_WARNING

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;
typedef long long ll;

ll N, tmp;
vector<ll> road, gas;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (ll i = 1; i < N; i++) {
		cin >> tmp;
		road.push_back(tmp);
	}

	for (ll i = 0; i < N; i++) {
		cin >> tmp;
		gas.push_back(tmp);
	}

	ll res = 0, min_val = LLONG_MAX;

	for (ll i = 0; i < N - 1; i++) {
		min_val = min(min_val, gas[i]);
		res += min_val * road[i];
	}

	cout << res << "\n";
}